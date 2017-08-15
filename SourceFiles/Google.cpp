#include "Google.h"

#include <QFile>
#include <QNetworkReply>
#include <QXmlStreamReader>

#include "OAuth2.h"

Google::Google() {
    mOAuth2 = makeOAuth2();

    connect(mOAuth2, &OAuth2::granted, this, &Google::download);
    connect(this, &Google::downloaded, this, &Google::parse);
}

Google::~Google() {
    delete mOAuth2;
}

void Google::download() {
    QNetworkReply *reply = mOAuth2->get(GET_URL);

    connect(reply, &QNetworkReply::finished, [=]() {
        QFile file(CONTACT_FILE);

        if (reply->error() != QNetworkReply::NoError) {
            return;
        }

        if (!file.open(QIODevice::WriteOnly)) {
            return;
        }

        QTextStream textStream(&file);
        textStream << reply->readAll();

        file.close();

        emit downloaded();
    });
}

void Google::forceSynchronize() {
    mOAuth2->grant();
}

QMap<QString, QVector<QString>> Google::getContacts() {
    return mContacts;
}

void Google::parse() {
    QFile file(CONTACT_FILE);

    if (!file.open(QIODevice::ReadOnly)) {
        return;
    }

    QXmlStreamReader xml;
    xml.setDevice(&file);

    while (!xml.atEnd()) {
        if (xml.name() == "entry" && xml.isStartElement()) {
            QString name;
            QVector<QString> number;

            while (!(xml.name() == "entry" && xml.isEndElement())) {
                if (xml.name() == "title") {
                    name = xml.readElementText();
                }
                if (xml.name() == "phoneNumber") {
                    number << xml.readElementText().replace(" ", "");
                }

                xml.readNextStartElement();
            }

            if (!name.isEmpty() && !number.isEmpty()) {
                mContacts.insert(name, number);
            }
        }

        xml.readNextStartElement();
    }

    file.close();

    emit parsed();
}

void Google::synchronize() {
    if (!QFile(CONTACT_FILE).exists()) {
        forceSynchronize();
    }

    parse();
}

OAuth2 *Google::makeOAuth2() {
    OAuth2 *oAuth2 = new OAuth2();

    oAuth2->setAccessTokenUrl(ACCESS_TOKEN_URL);
    oAuth2->setAuthorizationUrl(AUTHORIZATION_URL);
    oAuth2->setClientIdentifier(CLIENT_IDENTIFIER);
    oAuth2->setClientIdentifierSharedKey(CLIENT_IDENTIFIER_SHARED_KEY);
    oAuth2->setScope(SCOPE);

    return oAuth2;
}
