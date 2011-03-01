#include "TPR_GUI_MainPanel.h"
#include "TPR_GUI_PreferencesTab.h"

#include<QTabWidget>

TPR_GUI_MainPanel::TPR_GUI_MainPanel(QTabWidget *parent)
    : QTabWidget(parent)
{
    m_pPrefTab =  new TPR_GUI_PreferencesTab( this );
    addTab(m_pPrefTab, "Preferences");
}

TPR_GUI_MainPanel::~TPR_GUI_MainPanel()
{

}

TPR_GUI_PreferencesTab* TPR_GUI_MainPanel::getPreferencesTab()
{
    return m_pPrefTab;
}
