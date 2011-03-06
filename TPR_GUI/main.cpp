#include <QtGui/QApplication>
#include "TPR_GUI_ReportPanel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TPR_GUI_ReportPanel w;
    w.show();
    return a.exec();
}
