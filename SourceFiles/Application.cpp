#include "Application.h"

#include "ContactWindow.h"
#include "Google.h"
#include "MainWindow.h"
#include "SMS.h"

Application::Application(int &argc, char **argv) : QApplication(argc, argv) {
    mGoogle = new Google();
    mContactWindow = new ContactWindow();

    mSMS = new SMS();
    mMainWindow = new MainWindow();

    mGoogle->synchronize();
}

Application::~Application() {
    delete mMainWindow;
    delete mSMS;

    delete mContactWindow;
    delete mGoogle;
}

ContactWindow *Application::getContactWindow() {
    return mContactWindow;
}

Google *Application::getGoogle() {
    return mGoogle;
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
