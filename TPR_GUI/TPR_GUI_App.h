#ifndef TPR_GUI_APP_H
#define TPR_GUI_APP_H

#include "TPR_GUI_ReportPanel.h"

#include <QObject>
#include <QSystemTrayIcon>
#include <QMenu>

class TPR_GUI_App : public QObject
{
    Q_OBJECT
public:
    TPR_GUI_App();

public slots:
    void onGenerateReport();
    void onExit();
    void onReportWaste();


private:
    void createMenu();

private:
    QMenu*					m_pAppMenu;
    QSystemTrayIcon*		m_pTrayIcon;
    TPR_GUI_ReportPanel*	m_pReportPannel;

};

#endif // TPR_GUI_APP_H
