#include "OAuth2.h"

#include <QOAuthHttpServerReplyHandler>
#include <QtGui/QDesktopServices>

OAuth2::OAuth2() {
    mReplyHandler = makeReplyHandler();

    setReplyHandler(mReplyHandler);

    connect(this, &OAuth2::authorizeWithBrowser, this, &QDesktopServices::openUrl);
}

OAuth2::~OAuth2() {
    delete mReplyHandler;
}

void OAuth2::grant() {
    QOAuth2AuthorizationCodeFlow::grant();
}

QOAuthHttpServerReplyHandler *OAuth2::makeReplyHandler() {
    QOAuthHttpServerReplyHandler *replyHandler = new QOAuthHttpServerReplyHandler(PORT);

    return replyHandler;
}
