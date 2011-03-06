#ifndef TPR_BANK_GLOBAL_H
#define TPR_BANK_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TPR_BANK_LIBRARY)
#  define TPR_BANKSHARED_EXPORT Q_DECL_EXPORT
#else
#  define TPR_BANKSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // TPR_BANK_GLOBAL_H
