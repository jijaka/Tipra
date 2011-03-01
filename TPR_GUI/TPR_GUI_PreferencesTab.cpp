#include "TPR_GUI_PreferencesTab.h"
#include "TPR_GUI_common.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>

TPR_GUI_PreferencesTab::TPR_GUI_PreferencesTab( QWidget* parent ):
        QWidget(parent)
{
    QVBoxLayout* pVLay = new QVBoxLayout();
    pVLay->setMargin(LAY_MARGIN);
    pVLay->setSpacing(LAY_SPACING);
    QLabel* pTabLabel = new QLabel("Test label...");
    QTextEdit* pText = new QTextEdit("Test text...");
    pVLay->addWidget(pTabLabel);
    pVLay->addWidget(pText);
    setLayout(pVLay);
}
