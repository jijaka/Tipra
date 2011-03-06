#include "TPR_GUI_ReportPanel.h"
#include "TPR_GUI_common.h"

#include <QLayout>
#include <QLabel>
#include <QTextEdit>
#include <QDate>
#include <QCloseEvent>
#include <QIcon>
#include <QDir>


TPR_GUI_ReportPanel::TPR_GUI_ReportPanel(QWidget *parent)
    : QWidget(parent)
{
	setWindowTitle("Report generator");
	initialize();
}

TPR_GUI_ReportPanel::~TPR_GUI_ReportPanel()
{

}

/**
  * Initializes main (generate report) panel.
  */
void TPR_GUI_ReportPanel::initialize()
{
	QVBoxLayout* pVLay = new QVBoxLayout();
	QHBoxLayout* pHLay;
    pVLay->setMargin(LAY_MARGIN);
    pVLay->setSpacing(LAY_SPACING);

	//Label
    QLabel* pReportLabel = new QLabel("Generate report:");
	pVLay->addWidget(pReportLabel);

	//From .. To
	pHLay = new QHBoxLayout();
	QIcon iconCalendar("C:/Development/Tipra/etc/icon_calendar.png");
	QLabel* pFromLabel = new QLabel("From:");
	m_pFromDate = new QDateEdit( TPR_GUI::beginOfMonth() );
	m_pCalendarForm = new QPushButton(iconCalendar, "");
	QLabel* pToLabel = new QLabel("To:");
	m_pToDate =  new QDateEdit ( QDate::currentDate() );
	m_pCalendarTo = new QPushButton(iconCalendar, "");
	pHLay->addWidget(pFromLabel);
	pHLay->addWidget(m_pFromDate);
	pHLay->addWidget(m_pCalendarForm);
	pHLay->addWidget(pToLabel);
	pHLay->addWidget(m_pToDate);
	pHLay->addWidget(m_pCalendarTo);
	pVLay->addLayout(pHLay);

	//Printers
	QLabel* pPrintersLabel = new QLabel("Printers:");
	m_pAvaliblePrinters = new QListWidget();
	pVLay->addWidget(pPrintersLabel);
	pVLay->addWidget(m_pAvaliblePrinters);
	
	//Save as:
	pHLay = new QHBoxLayout();
	QLabel* pSaveAsLabel = new QLabel("Save as:");
	m_pPathEdit = new QLineEdit( QDir::currentPath() );
	m_pGetPath = new QPushButton(" ... ");
	pHLay->addWidget( pSaveAsLabel );
	pHLay->addWidget( m_pPathEdit );
	pHLay->addWidget( m_pGetPath );
	pVLay->addLayout(pHLay);

	//Create...
	m_pGenerate = new QPushButton(" Generate ");
	pVLay->addWidget(m_pGenerate);

	setLayout(pVLay);
}

 void TPR_GUI_ReportPanel::closeEvent(QCloseEvent *event)
 {
     hide();
     event->ignore();
 }