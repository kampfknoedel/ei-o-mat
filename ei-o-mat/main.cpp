#include "eingabefenster.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Eingabefenster w;
    w.show();
    return a.exec();
}
