/*
 * Account.cpp
 *
 *  Created on: Apr 5, 2020
 *      Author: jbbui
 */

#include "Account.h"

#include <vector>
using namespace std;

Account::Account() {
	principle = 0.0;
	annualInterest = 0.0;
	monthlyDeposit = 0.0;
	numYears = 0;
	setTotalPerYear();
	setTotalPerYearWODeposit();

}

Account::~Account() {
}

void Account::setNumYears(int numYears){
	this->numYears = numYears;
	this->resizeVectors(numYears);
}

void Account::setAnnualInterest(double annualInterest) {
	this->annualInterest = annualInterest;
	this->updateVectors();
}

void Account::setMonthlyDeposit(double monthlyDeposit) {
	this->monthlyDeposit = monthlyDeposit;
	this->updateVectors();
}

void Account::setPrinciple(double principle) {
	this->principle = principle;
	this->updateVectors();
}

void Account::setTotalPerYear(){
	unsigned int i = 0;
	for(i = 0; i < totalPerYear.size(); ++i){
		if(i == 0){
			totalPerYear.at(i) = ((principle + monthlyDeposit * 12) * annualInterest) + (principle + monthlyDeposit * 12);
			interestPerYear.at(i) = (principle + monthlyDeposit * 12) * annualInterest;
		}
		else{
			totalPerYear.at(i) = ((totalPerYear.at(i - 1) + monthlyDeposit*12) * annualInterest) + (totalPerYear.at(i - 1) + monthlyDeposit*12);
			interestPerYear.at(i) = (totalPerYear.at(i - 1) + monthlyDeposit*12) * annualInterest;
		}
	}
}



void Account::setTotalPerYearWODeposit(){
	unsigned int i = 0;
	for(i = 0; i < totalPerYearWODeposit.size(); ++i){
		if(i == 0){
			totalPerYearWODeposit.at(i) = (principle * annualInterest) + principle;
			interestPerYearWODeposit.at(i) = principle * annualInterest;
		}
		else{
			totalPerYearWODeposit.at(i) = (totalPerYearWODeposit.at(i - 1) * annualInterest) + totalPerYearWODeposit.at(i - 1);
			interestPerYearWODeposit.at(i) = totalPerYearWODeposit.at(i - 1) * annualInterest;
		}
	}

}

void Account::resizeVectors(int i){
	this->totalPerYear.resize(i);
	this->interestPerYear.resize(i);
	this->totalPerYearWODeposit.resize(i);
	this->interestPerYearWODeposit.resize(i);
	this->updateVectors();
}

void Account::updateVectors(){
	this->setTotalPerYear();
	this->setTotalPerYearWODeposit();
}



