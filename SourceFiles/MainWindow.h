#ifndef KDECONNECT_SMS_MAIN_WINDOW_H
#define KDECONNECT_SMS_MAIN_WINDOW_H

#include <QMainWindow>

class QBoxLayout;
class QLineEdit;
class QPushButton;
class QTextEdit;

class MainWindow : public QMainWindow {
public:
    MainWindow();
    ~MainWindow();

    bool checkMessageInput();
    bool checkNumberInput();
    QString getMessage();
    QString getNumber();

private:
    QWidget *makeCentralWidget();
    QBoxLayout *makeLayout();
    QTextEdit *makeMessageInput();
    QLineEdit *makeNumberInput();
    QPushButton *makeSendButton();
    void setWindowSize(const QSize &size);

private:
    const QSize SIZE = { 320, 320 };
    const QString TITLE = "KDE Connect - SMS";

    QWidget *mCentralWidget = nullptr;
    QBoxLayout *mLayout = nullptr;
    QTextEdit *mMessageInput = nullptr;
    QLineEdit *mNumberInput = nullptr;
    QPushButton *mSendButton = nullptr;
};

#endif //KDECONNECT_SMS_MAIN_WINDOW_H
