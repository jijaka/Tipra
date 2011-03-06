#include "TPR_GUI_App.h"

#include <QAction>
#include <QApplication>


TPR_GUI_App::TPR_GUI_App()
{
    m_pAppMenu = NULL;
    m_pTrayIcon = NULL;
    m_pReportPannel = NULL;
    QIcon icon("C:/Development/Tipra/etc/icon_red.png");
    m_pTrayIcon = new QSystemTrayIcon(icon);
    createMenu();
    m_pTrayIcon->show();
}

void TPR_GUI_App::createMenu()
{
    if(m_pAppMenu)
        delete m_pAppMenu;
    m_pAppMenu = new QMenu("Tipra!");
    QAction* pAct = m_pAppMenu->addAction("Generate report");
    connect( pAct, SIGNAL(triggered()), this, SLOT( onGenerateReport()) );
    m_pAppMenu->addSeparator();
    pAct = m_pAppMenu->addAction("Report waste");
    connect( pAct, SIGNAL(triggered()), this, SLOT(onReportWaste()) );
    pAct = m_pAppMenu->addAction("Exit");
    connect( pAct, SIGNAL(triggered()), this, SLOT(onExit()) );
    if(m_pTrayIcon){
        m_pTrayIcon->setContextMenu(m_pAppMenu);
    }
}

void TPR_GUI_App::onExit()
{
    m_pTrayIcon->hide();
    QApplication::instance()->quit();
}
void TPR_GUI_App::onGenerateReport()
{
    if( !m_pReportPannel )
        m_pReportPannel = new TPR_GUI_ReportPanel();
    m_pReportPannel->show();
}
void TPR_GUI_App::onReportWaste()
{

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	TPR_GUI_App appTipra;
    return a.exec();
}
