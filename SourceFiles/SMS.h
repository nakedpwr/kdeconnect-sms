#ifndef KDECONNECT_SMS_SMS_H
#define KDECONNECT_SMS_SMS_H

#include <QObject>

class SMS : public QObject {
    Q_OBJECT

public:
    SMS();
    ~SMS();

    QString getDeviceId();
    void send();

signals:
    void sent();
};

#endif //KDECONNECT_SMS_SMS_H
