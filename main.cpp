#include <QApplication>
#include "windowframe.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString user{"generic@email.it"};
    QString privilage{"Admin"};
    WindowFrame w(user, privilage);

    w.show();
    return a.exec();
}
