#ifndef TPR_GUI_REPORTPANEL_H
#define TPR_GUI_REPORTPANEL_H

#include "TPR_GUI_PreferencesTab.h"
#include "TPR_Bank\TPR_Bank_Dao.h"

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QDateTimeEdit>
#include <QLineEdit>
#include <QListWidget>

class TPR_GUI_ReportPanel : public QWidget
{
    Q_OBJECT

public:
    TPR_GUI_ReportPanel(QWidget *parent = 0);
    virtual ~TPR_GUI_ReportPanel();

protected:
     void closeEvent(QCloseEvent *event);  

private:
    void initialize();

private:
	TPR_Bank_Dao* m_pDaoTipra;
	//UI Elemnts
	QPushButton*	m_pGenerate;
	QPushButton*	m_pCalendarForm;
	QPushButton*	m_pCalendarTo;
	QPushButton*	m_pSelectAll;
	QPushButton*	m_pDeselectAll;
	QPushButton*	m_pGetPath;
	QLineEdit*		m_pPathEdit;
	QDateTimeEdit*	m_pFromDate;
	QDateTimeEdit*	m_pToDate;
	QListWidget*	m_pAvaliblePrinters;
};

#endif // TPR_GUI_MAINPANEL_H
