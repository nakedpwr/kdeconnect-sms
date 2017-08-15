#include "SMS.h"

#include <QProcess>

#include "Application.h"
#include "Helper.h"
#include "MainWindow.h"

SMS::SMS() {
}

SMS::~SMS() {
}

QString SMS::getDeviceId() {
    QString program = "kdeconnect-cli";
    QStringList arguments = {
            "--list-available",
            "--id-only"
    };

    QProcess process;
    process.start(program, arguments);
    process.waitForFinished();

    return process.readAllStandardOutput().simplified();
}

void SMS::send() {
    if (!App->getMainWindow()->checkNumberInput()) {
        return;
    }

    if (!App->getMainWindow()->checkMessageInput()) {
        return;
    }

    QString program = "kdeconnect-cli";
    QStringList arguments = {
        "--device", getDeviceId(),
        "--destination", App->getMainWindow()->getNumber(),
        "--send-sms", App->getMainWindow()->getMessage()
    };

    QProcess process;
    process.start("kdeconnect-cli", arguments);
    process.waitForFinished();

    emit sent();
}
