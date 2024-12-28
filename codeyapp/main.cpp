#include "writeBook.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    writeBook w;
    w.show();
    return a.exec();
}
