#include "LectureQt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LectureQt w;
    w.show();
    return a.exec();
}
