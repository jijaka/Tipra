#include "TPR_Bank_Dao.h"
#include <iostream>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>

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
     
        int printerCol = query.record().indexOf("tpr_printer_name");
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
    return result;
}
bool TPR_Bank_Dao::insertRecord(QList<QString> args)
{
    return false;
}
