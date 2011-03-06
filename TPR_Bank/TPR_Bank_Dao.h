#ifndef TPR_BANK_DAO_H
#define TPR_BANK_DAO_H

#include "TPR_Bank_global.h"

#include <QObject>
#include <QSqlDatabase>
#include <QList>
#include <QDateTime>

class TPR_BANKSHARED_EXPORT TPR_Bank_Dao : public QObject
{

public:
    TPR_Bank_Dao( QString strBankPath );
    ~TPR_Bank_Dao();
    void insertTestValue();
    QList<QString> getPrintersNames();
    QList<QString> getReport(QDateTime from,  QDateTime to);
    bool insertRecord(QList<QString> args);

private:
    QSqlDatabase    m_dbBank;
};



#endif // TPR_BANK_DAO_H
