#include "flowlightwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FlowLightWidget w;
    w.resize(800,800);
    w.setStyleSheet("background-color:#000000");
    w.show();
    return a.exec();
}
