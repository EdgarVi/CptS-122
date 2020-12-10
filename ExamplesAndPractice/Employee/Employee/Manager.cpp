#include "Manager.h"

double Manager::calculatePay()
{

	double pay = 0.0;

	if (!mIsSalaried) {
		//hourly
		pay = Employee::calculatePay();
	}
}
