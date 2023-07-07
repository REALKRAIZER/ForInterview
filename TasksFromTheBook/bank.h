#ifndef BankAccount_H_
#define BankAccount_H_
#include <iostream>
class BankAccount
{
private:
	std::string m_name;
	std::string m_number;
	double m_balans;
public:
	BankAccount() {m_name = "no name"; m_number = "no number"; m_balans = 0;}
	BankAccount(std::string name, std::string number,double balans);
	void show() const;
	void deposite(double sum);
	void withdraw(double sum);
};
#endif