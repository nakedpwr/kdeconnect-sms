#include "Application.h"

#include "MainWindow.h"
#include "SMS.h"

Application::Application(int &argc, char **argv) : QApplication(argc, argv) {
    mSMS = new SMS();
    mMainWindow = new MainWindow();
}

Application::~Application() {
    delete mMainWindow;
    delete mSMS;
}

MainWindow *Application::getMainWindow() {
    return mMainWindow;
}

SMS *Application::getSMS() {
    return mSMS;
}

int Application::run() {
    mMainWindow->show();

    return QApplication::exec();
}
