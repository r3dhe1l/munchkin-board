#include "munchkinboard.h"
#include <QtWidgets/QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    munchkinboard board;
    board.show();
    return app.exec();
}
