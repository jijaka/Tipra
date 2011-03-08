#include "TPR_Bank_Dao.h"
#include "TPR_Bank_common.h"

#include <iostream>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QList>

TPR_Bank_Dao::TPR_Bank_Dao( QString strBankPath )
{
    m_dbBank = QSqlDatabase::addDatabase("QSQLITE");
    m_dbBank.setDatabaseName( strBankPath );
    if (!m_dbBank.open()) {
        std::cerr<< "Cannot open database;" << std::endl;
    }
}

TPR_Bank_Dao::~TPR_Bank_Dao()
{
    if( m_dbBank.isOpen() )
        m_dbBank.close();
}

void TPR_Bank_Dao::insertTestValue()
{
    if ( m_dbBank.transaction() ) {
        QSqlQuery query;
        query.exec( "INSERT INTO tipra VALUES (NULL, 'TEST', 'TEST', 'YYYY-MM-DD HH:MM', 42)" );
        m_dbBank.commit();
    } else {
        std::cerr<< "Cannot open transaction;" << std::endl;
    }
    getchar();
    exit(0);
}

QList<QString> TPR_Bank_Dao::getPrintersNames()
{
    QList<QString> result;
    bool bTransaction = m_dbBank.transaction();
    if ( bTransaction ){
        QSqlQuery query("SELECT DISTINCT tpr_printer_name FROM tipra;");
        int printerCol = query.record().indexOf(TPR_PRINTER_NAME);
        while (query.next()) {
            QString strPrinterName = query.value(printerCol).toString();
            result.push_back( strPrinterName );
        }
        query.clear();
        m_dbBank.commit();
    } else {
        std::cerr<< "TPR_Bank_Dao::getPrintersNames(): Cannot open transaction;" << std::endl;
    }
    return result;
}
QList<QString> TPR_Bank_Dao::getReport(QDateTime from,  QDateTime to)
{
    QList<QString> result;
	
	bool bTransaction = m_dbBank.transaction();
    if ( bTransaction ){
		//:from "2011-03-05 00:00:00" 
		//:to   "2011-03-05 24:00:00"
        QSqlQuery query;
		QString dtFormat("yyyy-MM-dd hh:mm:ss");
		query.prepare("SELECT * FROM tipra WHERE tpr_date BETWEEN :from AND :to ORDER BY tpr_date;");
		query.bindValue( ":from", from.toString(dtFormat) );
        query.bindValue( ":to",   to.toString(dtFormat)   );
		query.exec();
		while (query.next()) {
			QString strRow = QString("%1;%2;%3;%4;%5;")
				.arg(query.value(0).toString())
				.arg(query.value(1).toString())
				.arg(query.value(2).toString())
				.arg(query.value(3).toString())
				.arg(query.value(4).toString());
            result.push_back( strRow );
        }
        query.clear();
        m_dbBank.commit();
    } else {
        std::cerr<< "TPR_Bank_Dao::getReport(): Cannot open transaction;" << std::endl;
    }
    return result;
}
bool TPR_Bank_Dao::insertRecord(QList<QString> args)
{
	bool result = true;
	if ( args.count() < 1 )
		result = false;
	else {
		if (args.count() < 5) {
			while(args.count() != 5)
				args.push_back("");
		}
		bool bTransaction = m_dbBank.transaction();
		if ( bTransaction ){
			QSqlQuery query;
			query.prepare("INSERT INTO tipra VALUES ( ?, ?, ?, ?, ? );");
			QString strBindParam;
			foreach( strBindParam, args ){
				if( strBindParam.isEmpty() )
					query.addBindValue( QVariant() );
				else
					query.addBindValue(strBindParam);
			}
			result = query.exec();
			if (result)
				m_dbBank.commit();
			else 
				m_dbBank.rollback();
		} else {
			std::cerr<< "TPR_Bank_Dao::insertRecord(): Cannot open transaction;" << std::endl;
			result = false;
		}
	}
	return result;
}

bool TPR_Bank_Dao::insertRecord(LPCTSTR printer, LPCTSTR document, int pages, LPCTSTR status)
{
	QString strArg;
	QList<QString> args;
	args.push_back(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
	args.push_back(QString::fromWCharArray(printer));
	args.push_back(QString::fromWCharArray(document));
	if ( pages <= 0)
		strArg="";
	else 
		strArg = QString("%1").arg(pages);
	args.push_back(strArg);
	args.push_back(QString::fromWCharArray(status));
	return insertRecord(args);
}