#ifndef KDECONNECT_SMS_O_AUTH2_H
#define KDECONNECT_SMS_O_AUTH2_H

#include <QOAuth2AuthorizationCodeFlow>

class QOAuthHttpServerReplyHandler;

class OAuth2 : public QOAuth2AuthorizationCodeFlow {
public:
    OAuth2();
    ~OAuth2();

    void grant() override;

private:
    QOAuthHttpServerReplyHandler *makeReplyHandler();

private:
    const quint16 PORT = 8080;

    QOAuthHttpServerReplyHandler *mReplyHandler;
};

#endif //KDECONNECT_SMS_O_AUTH2_H
