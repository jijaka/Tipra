#ifndef TPR_GUI_COMMON_H
#define TPR_GUI_COMMON_H

#include <QDate>
#define LAY_MARGIN 2
#define LAY_SPACING 3

namespace TPR_GUI{
	static  QDate beginOfMonth()
	{
		QDate cur = QDate::currentDate();
		return QDate(cur.year(),cur.month(),1);
	}
}

#endif // TPR_GUI_COMMON_H
