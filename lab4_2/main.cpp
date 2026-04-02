#include <QApplication>
#include "CarWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CarWindow window;
    window.show();
    return app.exec();
}
