#include "MainWindow.h"

#include <QAction>
#include <QBoxLayout>
#include <QIntValidator>
#include <QLineEdit>
#include <QListWidgetItem>
#include <QPushButton>
#include <QTextEdit>

#include "Application.h"
#include "ContactWindow.h"
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

    return ok;
}

QString MainWindow::getMessage() {
    return mMessageInput->toPlainText();
}

QString MainWindow::getNumber() {
    return mNumberInput->text();
}

QLineEdit *MainWindow::getNumberInput() {
    return mNumberInput;
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
        QAction *selectContact = new QAction();
        selectContact->setIcon(QIcon("Assets/Images/Contacts.png"));

        mNumberInput = new QLineEdit();
        mNumberInput->addAction(selectContact, QLineEdit::ActionPosition::TrailingPosition);

        connect(App->getSMS(), &SMS::sent, mNumberInput, &QLineEdit::clear);
        connect(selectContact, &QAction::triggered, App->getContactWindow(), &ContactWindow::show);
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
