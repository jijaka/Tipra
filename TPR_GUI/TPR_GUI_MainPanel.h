#ifndef TPR_GUI_MAINPANEL_H
#define TPR_GUI_MAINPANEL_H

#include "TPR_GUI_PreferencesTab.h"
#include <QTabWidget>

class TPR_GUI_MainPanel : public QTabWidget
{
    Q_OBJECT

public:
    TPR_GUI_MainPanel(QTabWidget *parent = 0);
    virtual ~TPR_GUI_MainPanel();
    TPR_GUI_PreferencesTab* getPreferencesTab();

private:
    TPR_GUI_PreferencesTab* m_pPrefTab;
};

#endif // TPR_GUI_MAINPANEL_H
