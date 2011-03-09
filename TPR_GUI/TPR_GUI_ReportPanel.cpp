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
	m_pGetPath = NULL;
	m_pPathEdit = NULL;
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
	QSpacerItem* pHSpacer;

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
	pHSpacer = new QSpacerItem(15,0,QSizePolicy::Maximum);
	pHLay->addSpacerItem(pHSpacer);
	pHLay->addWidget(pToLabel);
	pHLay->addWidget(m_pToDate);
	pHSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding);
	pHLay->addSpacerItem(pHSpacer);
	pVLay->addLayout(pHLay);

	//Printers
	QLabel* pPrintersLabel = new QLabel(tr("Printers:"));
	m_pAvaliblePrinters = new QTableWidget(5,2);
	pVLay->addWidget(pPrintersLabel);
	pVLay->addWidget(m_pAvaliblePrinters);
	
	//Save as:
	pHLay = new QHBoxLayout();
	pHLay->setMargin(LAY_MARGIN);
    pHLay->setSpacing(LAY_SPACING);
	QLabel* pSaveAsLabel = new QLabel(tr("Save as:"));
	m_pPathEdit = new QLineEdit( QDir::currentPath() );
	m_pGetPath = new QPushButton("...");
	m_pGetPath->setSizePolicy(QSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed));
	m_pGetPath->setMaximumSize(30, 20);
	pHLay->addWidget( pSaveAsLabel );
	pHLay->addWidget( m_pPathEdit );
	pHLay->addWidget( m_pGetPath );
	pVLay->addLayout(pHLay);

	//Create...
	m_pGenerate = new QPushButton(tr("Generate"));
	m_pGenerate->setSizePolicy(QSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed));
	m_pGenerate->setMaximumSize(150, 30);
	pVLay->addWidget(m_pGenerate);

	setLayout(pVLay);

	connect( m_pGetPath, SIGNAL(clicked()), this, SLOT(onChangePath()) );
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
	QMessageBox(QMessageBox::Information, "Not", "Implemented yet... :(", QMessageBox::Cancel).exec();
}

void TPR_GUI_ReportPanel::onChangePath()
{
	QString fileName = m_pPathEdit->text();
	QString filePath ("");
	if( QDir(fileName).exists() )
		filePath = QDir(fileName).absolutePath();
	fileName = QFileDialog::getOpenFileName(this, tr("Open File"), filePath);
	if(!fileName.isEmpty())
		m_pPathEdit->setText(fileName);
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