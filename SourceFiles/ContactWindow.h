#ifndef KDECONNECT_SMS_CONTACT_WINDOW_H
#define KDECONNECT_SMS_CONTACT_WINDOW_H

#include <QWidget>

class QBoxLayout;
class QListWidget;
class QListWidgetItem;

class ContactWindow : public QWidget {
public:
    ContactWindow();
    ~ContactWindow();

private:
    void fillContactList();
    void fillNumber(QListWidgetItem *item);
    QListWidget *makeContactList();
    QBoxLayout *makeLayout();

private:
    const QString TITLE = "Contacts";

    QListWidget *mContactList = nullptr;
    QBoxLayout *mLayout = nullptr;
};

#endif //KDECONNECT_SMS_CONTACT_WINDOW_H
