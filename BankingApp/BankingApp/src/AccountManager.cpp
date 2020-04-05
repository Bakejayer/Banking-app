/*
 * AccountManager.cpp
 *
 *  Created on: Apr 5, 2020
 *      Author: jbbui
 */

#include "AccountManager.h"
#include "Account.h"

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

AccountManager::AccountManager() {//instantiates variables
	userAccount = new Account();
    doubleGetter = 0.0;
    intGetter = 0;
}

AccountManager::~AccountManager() {//deletes references
	delete userAccount;
}

void AccountManager::runAccountManager(){//runs the Account manager
	getUserValues();
	cout << string(30, '\n');
	displayInputVals();
	displayTotals();
	displayTotalsWOMonthlyDeposit();
}

void AccountManager::getUserValues(){
	cout << "       Airgead Banking       " << endl;
	cout << "*****************************" << endl;

	cout << "Please enter your initial investment: " << endl;
	inputCheckerDouble();
	userAccount->setPrinciple(doubleGetter);

	cout << "Please enter your monthly deposit: " << endl;
	inputCheckerDouble();
	userAccount->setMonthlyDeposit(doubleGetter);

	cout << "Please enter your annual interest percentage: " << endl;
	inputCheckerDouble();
	doubleGetter /= 100;
	userAccount->setAnnualInterest(doubleGetter);

	cout << "Please enter the number of investment years: " << endl;
	inputCheckerInt();
	userAccount->setNumYears(intGetter);
}

void AccountManager::displayInputVals(){
	cout << fixed << setprecision(2);
	cout << "       Airgead Banking       " << endl;
	cout << "*****************************" << endl;
	cout << "Initial Investment Amount: $" << userAccount->getPrinciple() << endl;
	cout << "Monthly Deposit: $" << userAccount->getMonthlyDeposit() << endl;
	cout << "Annual Interest: $" << userAccount->getAnnualInterest() * 100 << "%" << endl;
	cout << "Number of Years: $" << userAccount->getNumYears() << endl << endl;
}

void AccountManager::displayTotals(){
	int i;
	unsigned int j;
	cout << fixed << setprecision(2);
	cout << string(60, '*') << endl;
	cout << "        Balance and Interest With Monthly Deposit    " << endl;
	cout << string(60,'=') << endl;
	cout << "Year" << setw(28) << "Year End Balance($)" << setw(28) << "Year End Earned Interest($)" << endl;
	cout << string(60, '-') << endl;
	for(i = 0; i < userAccount->getNumYears(); ++i){
		j = i;
		cout << setw(4) << i + 1 << setw(28) << userAccount->getTotalPerYear(j) << setw(28) << userAccount->getInterestPerYear(j) << endl;
	}
	cout << endl;
}

void AccountManager::displayTotalsWOMonthlyDeposit(){
	int i;
	unsigned int j;
	cout << fixed << setprecision(2);
	cout << string(60, '*') << endl;
	cout << "        Balance and Interest Without Monthly Deposit   " << endl;
	cout << string(60,'=') << endl;
	cout << "Year" << setw(28) << "Year End Balance($)" << setw(28) << "Year End Earned Interest($)" << endl;
	cout << string(60, '-') << endl;
	for(i = 0; i < userAccount->getNumYears(); ++i){
		j = i;
		cout << setw(4) << i + 1 << setw(28) << userAccount->getTotalPerYearWODeposit(j) << setw(28) << userAccount->getInterestPerYearWODeposit(j) << endl;
	}
	cout << endl;
}
void AccountManager::inputCheckerDouble(){
	try{
		cin >> doubleGetter;
	}
	catch(exception& e){
		cout << "Please enter a valid input" << endl;
		inputCheckerDouble();
	}
}

void AccountManager::inputCheckerInt(){
	try{
		cin >> intGetter;
	}
	catch(exception& e){
		cout << "Please enter a valid input" << endl;
		inputCheckerInt();
	}
}
