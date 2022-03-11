#include "changenumberwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChangeNumberWindow w;
    w.setWindowTitle("Изменяемое число");
    w.resize(300, 250);
    w.show();
    return a.exec();
}
