#include "TPR_GUI_ReportPanel.h"
#include "TPR_GUI_common.h"

#include <QDate>
#include <QCloseEvent>
#include <QIcon>
#include <QDir>
#include <QtGui>
#include <QFileDialog>

TPR_GUI_ReportPanel::TPR_GUI_ReportPanel(QWidget *parent)
    : QWidget(parent)
{
	m_pDaoTipra = NULL;
	m_pGenerate = NULL;
	m_pSelectAll = NULL;
	m_pDeselectAll = NULL;
	m_pFromDate = NULL;
	m_pToDate = NULL;
	m_pAvaliblePrinters = NULL;
	setWindowTitle(tr("Tipra: Report Generator"));
	initialize();
	setWindowIcon(QIcon("C:/Development/Tipra/etc/icon_printer.png"));
	m_pDaoTipra = new TPR_Bank_Dao("C:/Development/Tipra/etc/tpr_bank.db");
	updatePrinterInfo();
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
    QLabel* pReportLabel = new QLabel(tr("Generate report:"));
	pVLay->addWidget(pReportLabel);

	//From .. To
	pHLay = new QHBoxLayout();
	pHLay->setMargin(LAY_MARGIN);
    pHLay->setSpacing(LAY_SPACING);
	QIcon iconCalendar("C:/Development/Tipra/etc/icon_calendar.png");
	QLabel* pFromLabel = new QLabel(tr("From:"));
	m_pFromDate = new QDateEdit( TPR_GUI::beginOfMonth() );
	m_pFromDate->setCalendarPopup(true);
	QLabel* pToLabel = new QLabel(tr("To:"));
	m_pToDate =  new QDateEdit ( QDate::currentDate() );
	m_pToDate->setCalendarPopup(true);
	pHLay->addWidget(pFromLabel);
	pHLay->addWidget(m_pFromDate);
	pHLay->insertSpacing(-1,15);
	pHLay->addWidget(pToLabel);
	pHLay->addWidget(m_pToDate);
	pHLay->insertStretch(-1);
	pVLay->addLayout(pHLay);

	//Printers & Generate
	QLabel* pPrintersLabel = new QLabel(tr("Printers:"));
	m_pAvaliblePrinters = new QTableWidget(5,2);
	pHLay = new QHBoxLayout();
	QVBoxLayout* pVSelectLay = new QVBoxLayout();
	pHLay->setMargin(LAY_MARGIN);
    pHLay->setSpacing(LAY_SPACING);
	m_pSelectAll = new QPushButton(tr("Select All"));
	m_pDeselectAll = new QPushButton(tr("Deselect All"));
	pVLay->addWidget(pPrintersLabel);			//Label
	pHLay->addWidget(m_pAvaliblePrinters);		//Label/List
	pVSelectLay->addWidget(m_pSelectAll);		//Label/List|Select
	pVSelectLay->addWidget(m_pDeselectAll);		//Label/List|Select/Deselect
	pVSelectLay->insertStretch(-1);
	m_pGenerate = new QPushButton(tr("Generate"));
	m_pGenerate->setSizePolicy(QSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed));
	m_pGenerate->setMaximumSize(150, 30);
	pVSelectLay->addWidget(m_pGenerate);		//Label/List|Select/Deselect ... Generate
	pHLay->addLayout(pVSelectLay);
	pVLay->addLayout(pHLay);
	setLayout(pVLay);

	connect( m_pGenerate, SIGNAL(clicked()), this, SLOT(onGenerate()) );
}

 void TPR_GUI_ReportPanel::closeEvent(QCloseEvent *event)
 {
     hide();
     event->ignore();
 }

 QSize TPR_GUI_ReportPanel::sizeHint() const
 {
	 return QSize(400,400);
 }

void TPR_GUI_ReportPanel::onGenerate(){
	QString defFile = QString(tr("/%1-tpr-stat.csv"))
		.arg(QDate::currentDate().toString("ddMMyy")); 
	defFile = QDir::currentPath() + defFile;
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                            defFile, tr("Text CSV (*.csv)"));
}

void TPR_GUI_ReportPanel::updatePrinterInfo()
{
	if(m_pDaoTipra){
		m_pAvaliblePrinters->clear();
		QList<QString> ltPrinters =  m_pDaoTipra->getPrintersNames();
		QString eachPrinter;
		int i = 0;
		foreach( eachPrinter,  ltPrinters){
			m_pAvaliblePrinters->setCellWidget(i,0, new QCheckBox() );
			m_pAvaliblePrinters->setItem(i,1, new QTableWidgetItem(eachPrinter) );
			i++;
		}
	}
}