#include "uwu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    uwu w;
    w.show();
    return a.exec();
}
