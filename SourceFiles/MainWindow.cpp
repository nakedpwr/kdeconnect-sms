#include "MainWindow.h"

#include <QBoxLayout>
#include <QIntValidator>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

#include "Application.h"
#include "Helper.h"
#include "SMS.h"

MainWindow::MainWindow() {
    setCentralWidget(makeCentralWidget());
    setWindowTitle(TITLE);
    setWindowSize(SIZE);
}

MainWindow::~MainWindow() {
}

bool MainWindow::checkMessageInput() {
    bool ok = true;

    if (mMessageInput->toPlainText().isEmpty()) {
        ok = false;
    }

    return ok;
}

bool MainWindow::checkNumberInput() {
    bool ok = true;

    mNumberInput->text().toInt(&ok);

    return ok;
}

QString MainWindow::getMessage() {
    return mMessageInput->toPlainText();
}

QString MainWindow::getNumber() {
    return mNumberInput->text();
}

QWidget *MainWindow::makeCentralWidget() {
    if (mCentralWidget == nullptr) {
        mCentralWidget = new QWidget();
        mCentralWidget->setLayout(makeLayout());
    }

    return mCentralWidget;
}

QBoxLayout *MainWindow::makeLayout() {
    if (mLayout == nullptr) {
        mLayout = new QBoxLayout(QBoxLayout::TopToBottom);
        mLayout->addWidget(makeNumberInput());
        mLayout->addWidget(makeMessageInput());
        mLayout->addWidget(makeSendButton());
    }

    return mLayout;
}

QTextEdit *MainWindow::makeMessageInput() {
    if (mMessageInput == nullptr) {
        mMessageInput = new QTextEdit();

        connect(App->getSMS(), &SMS::sent, mMessageInput, &QTextEdit::clear);
    }

    return mMessageInput;
}

QLineEdit *MainWindow::makeNumberInput() {
    if (mNumberInput == nullptr) {
        mNumberInput = new QLineEdit();

        connect(App->getSMS(), &SMS::sent, mNumberInput, &QLineEdit::clear);
    }

    return mNumberInput;
}

void MainWindow::setWindowSize(const QSize &size) {
    resize(size);
}

QPushButton *MainWindow::makeSendButton() {
    if (mSendButton == nullptr) {
        mSendButton = new QPushButton();
        mSendButton->setText("Send");

        connect(mSendButton, &QPushButton::clicked, App->getSMS(), &SMS::send);
    }

    return mSendButton;
}
