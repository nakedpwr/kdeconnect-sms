#ifndef KDECONNECT_SMS_APPLICATION_H
#define KDECONNECT_SMS_APPLICATION_H

#include <QApplication>

class MainWindow;
class SMS;

class Application : public QApplication {
public:
    Application(int &argc, char **argv);
    ~Application();

    MainWindow *getMainWindow();
    SMS *getSMS();
    int run();

private:
    MainWindow *mMainWindow;
    SMS *mSMS;
};

#endif //KDECONNECT_SMS_APPLICATION_H
