#include <QtGui/QApplication>
#include "TPR_GUI_MainPanel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TPR_GUI_MainPanel w;
    w.show();
    return a.exec();
}
