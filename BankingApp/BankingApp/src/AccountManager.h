/*
 * AccountManager.h
 *
 *  Created on: Apr 5, 2020
 *      Author: jbbui
 */

#ifndef ACCOUNTMANAGER_H_
#define ACCOUNTMANAGER_H_

#include "Account.h"

class AccountManager {
public:
	AccountManager();
	virtual ~AccountManager();
	void getUserValues();
	void displayInputVals();
	double getDoubleGetter() const {return doubleGetter;};
	void setDoubleGetter(double doubleGetter) {this->doubleGetter = doubleGetter;};
	int getIntGetter() const {return intGetter;};
	void setIntGetter(int intGetter) {this->intGetter = intGetter;};
	void displayTotals();
	void displayTotalsWOMonthlyDeposit();
	void runAccountManager();
	void inputCheckerDouble();
	void inputCheckerInt();

private:
	Account* userAccount;
	double doubleGetter;
	int intGetter;

};

#endif /* ACCOUNTMANAGER_H_ */
