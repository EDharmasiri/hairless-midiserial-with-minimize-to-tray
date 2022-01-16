#include <QApplication>
#include "ui/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Projectgus");
    QCoreApplication::setOrganizationDomain("projectgus.com");
    QCoreApplication::setApplicationName("Hairless MIDI Serial Bridge");
    MainWindow w;
    return a.exec();
}
