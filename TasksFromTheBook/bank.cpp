#include <iostream>
#include "bank.h"
BankAccount::BankAccount(std::string name, std::string number,double balans)
{
	m_name = name;
	m_number = number;
	m_balans = balans;
}
void BankAccount::show() const
{
	using std::cout;
	using std::endl;
	cout << m_name << endl << m_number << endl << m_balans << endl;
}
void BankAccount::deposite(double sum)
{
	m_balans += sum;
}
void BankAccount::withdraw(double sum)
{
	m_balans -= sum;
}