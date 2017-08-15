#ifndef KDECONNECT_SMS_APPLICATION_H
#define KDECONNECT_SMS_APPLICATION_H

#include <QApplication>

class ContactWindow;
class Google;
class MainWindow;
class SMS;

class Application : public QApplication {
public:
    Application(int &argc, char **argv);
    ~Application();

    ContactWindow *getContactWindow();
    Google *getGoogle();
    MainWindow *getMainWindow();
    SMS *getSMS();
    int run();

private:
    ContactWindow *mContactWindow;
    Google *mGoogle;
    MainWindow *mMainWindow;
    SMS *mSMS;
};

#endif //KDECONNECT_SMS_APPLICATION_H
