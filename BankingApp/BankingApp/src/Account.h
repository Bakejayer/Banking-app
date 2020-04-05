/*
 * Account.h
 *
 *  Created on: Apr 5, 2020
 *      Author: jbbui
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <vector>
using namespace std;

class Account {
public:
	Account();
	virtual ~Account();
	double getAnnualInterest() const {return annualInterest;};
	void setAnnualInterest(double annualInterest);
	double getMonthlyDeposit() const {return monthlyDeposit;};
	void setMonthlyDeposit(double monthlyDeposit);
	int getNumYears() const {return numYears;};
	void setNumYears(int numYears);
	double getPrinciple() const {return principle;};
	void setPrinciple(double principle);
	void setTotalPerYear();
	void setTotalPerYearWODeposit();
	double getTotalPerYear(unsigned int index){return this->totalPerYear.at(index);};
	double getInterestPerYear(unsigned int index){return this->interestPerYear.at(index);};
	double getTotalPerYearWODeposit(unsigned int index){return this->totalPerYearWODeposit.at(index);};
	double getInterestPerYearWODeposit(unsigned int index){return this->interestPerYearWODeposit.at(index);};
	void resizeVectors(int i);
	void updateVectors();


private:
	double principle;
	double monthlyDeposit;
	double annualInterest;
	int numYears;
	vector<double> totalPerYear;
	vector<double> interestPerYear;
	vector<double> totalPerYearWODeposit;
	vector<double> interestPerYearWODeposit;
};

#endif /* ACCOUNT_H_ */
