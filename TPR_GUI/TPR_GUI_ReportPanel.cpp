#include "TPR_GUI_ReportPanel.h"
#include "TPR_GUI_common.h"

#include <QLayout>
#include <QLabel>
#include <QTextEdit>
#include <QDateTime>
#include <iostream>


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
	
	//Month from 
	QHBoxLayout* pHFromLay = new QHBoxLayout();
    setLayout(pVLay);
}