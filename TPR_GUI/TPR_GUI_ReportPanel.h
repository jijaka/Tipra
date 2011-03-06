#ifndef TPR_GUI_REPORTPANEL_H
#define TPR_GUI_REPORTPANEL_H

#include "TPR_GUI_PreferencesTab.h"
#include "TPR_Bank\TPR_Bank_Dao.h"

#include <QWidget>
#include <QListWidget>

class TPR_GUI_ReportPanel : public QWidget
{
    Q_OBJECT

public:
    TPR_GUI_ReportPanel(QWidget *parent = 0);
    virtual ~TPR_GUI_ReportPanel();
    
private:
    void initialize();
private:
	QListWidget* m_pTestList;
	TPR_Bank_Dao* m_pDaoTipra;
};

#endif // TPR_GUI_MAINPANEL_H
