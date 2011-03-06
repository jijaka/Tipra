#include "TPR_GUI_ReportPanel.h"
#include "TPR_GUI_common.h"

#include <QLayout>
#include <QLabel>
#include <QTextEdit>


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
    pVLay->setMargin(LAY_MARGIN);
    pVLay->setSpacing(LAY_SPACING);

	//Label
    QLabel* pReportLabel = new QLabel("Fill this form to generate report:");
	pVLay->addWidget(pReportLabel);

	//Test
	m_pTestList =  new QListWidget();
	pVLay->addWidget(m_pTestList);
	m_pDaoTipra = new TPR_Bank_Dao ( "C:/Development/Tipra/etc/tpr_bank.db" );
	m_pTestList->addItems(m_pDaoTipra->getPrintersNames());
	
	//Month from 
	QHBoxLayout* pHFromLay = new QHBoxLayout();
    setLayout(pVLay);
}