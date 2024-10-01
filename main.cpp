#include "trackmanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TrackManager w;
    w.show();
    return a.exec();
}
