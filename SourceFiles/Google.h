#ifndef KDECONNECT_SMS_GOOGLE_H
#define KDECONNECT_SMS_GOOGLE_H

#include <QObject>
#include <QMap>
#include <QUrl>
#include <QVector>

class OAuth2;

class Google : public QObject {
    Q_OBJECT
public:
    Google();
    ~Google();

    void download();
    void forceSynchronize();
    QMap<QString, QVector<QString>> getContacts();
    void parse();
    void synchronize();

signals:
    void downloaded();
    void parsed();

private:
    OAuth2 *makeOAuth2();

private:
    const QUrl ACCESS_TOKEN_URL = QUrl("https://accounts.google.com/o/oauth2/token");
    const QUrl AUTHORIZATION_URL = QUrl("https://accounts.google.com/o/oauth2/auth");
    const QString CLIENT_IDENTIFIER = QString("310852984325-2le55tj1vo35q12i3pruig5iufi7qe9g.apps.googleusercontent.com");
    const QString CLIENT_IDENTIFIER_SHARED_KEY = QString("8qOYGEI_tsmITdte9xr6H2Lv");
    const QString CONTACT_FILE = QString("/tmp/kdeconnect/Contact.xml");
    const QUrl GET_URL = QUrl("https://www.google.com/m8/feeds/contacts/default/full");
    const QString SCOPE = QString("https://www.googleapis.com/auth/contacts.readonly");

    OAuth2 *mOAuth2;

    QMap<QString, QVector<QString>> mContacts;
};

#endif //KDECONNECT_SMS_GOOGLE_H
