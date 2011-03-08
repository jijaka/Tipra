#ifndef TPR_BANK_DAO_H
#define TPR_BANK_DAO_H

#include "TPR_Bank_global.h"

#include <windows.h>
#include <QObject>
#include <QSqlDatabase>
#include <QList>
#include <QDateTime>

class TPR_BANKSHARED_EXPORT TPR_Bank_Dao : public QObject
{

public:
    TPR_Bank_Dao( QString strBankPath );
    ~TPR_Bank_Dao();
    //For TPR_GUI
	void insertTestValue();
    QList<QString> getPrintersNames();
    QList<QString> getReport(QDateTime from,  QDateTime to);
    //For TPR_Daemon
	bool insertRecord(LPCTSTR printer, LPCTSTR document, int pages, LPCTSTR status);

private:
    QSqlDatabase    m_dbBank;
	bool insertRecord(QList<QString> args);
};



#endif // TPR_BANK_DAO_H
