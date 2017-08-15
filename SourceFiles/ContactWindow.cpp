#include "ContactWindow.h"

#include <QBoxLayout>
#include <QLineEdit>
#include <QListWidget>

#include "Application.h"
#include "Google.h"
#include "Helper.h"
#include "MainWindow.h"

ContactWindow::ContactWindow() {
    setWindowTitle(TITLE);
    setLayout(makeLayout());

    connect(App->getGoogle(), &Google::parsed, this, &ContactWindow::fillContactList);
    connect(mContactList, &QListWidget::itemDoubleClicked, this, &ContactWindow::fillNumber);
}

ContactWindow::~ContactWindow() {
}

void ContactWindow::fillContactList() {
    for (auto contact : App->getGoogle()->getContacts().toStdMap()) {
        new QListWidgetItem(contact.first, mContactList);
    }
}

void ContactWindow::fillNumber(QListWidgetItem *item) {
    // TODO: select number if there are more than one
    QString number = App->getGoogle()->getContacts()[item->text()][0];

    App->getMainWindow()->getNumberInput()->setText(number);
    close();
}

QListWidget *ContactWindow::makeContactList() {
    if (mContactList == nullptr) {
        mContactList = new QListWidget();
    }

    return mContactList;
}

QBoxLayout *ContactWindow::makeLayout() {
    if (mLayout == nullptr) {
        mLayout = new QBoxLayout(QBoxLayout::TopToBottom);
        mLayout->addWidget(makeContactList());
    }

    return mLayout;
}
