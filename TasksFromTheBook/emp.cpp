#include "emp.h"
using std::cout;
using std::cin;
using std::endl;
std::ostream & operator<<(std::ostream & os, const abstr_emp & ae)
{
	cout << "First name: " << ae.fname << endl;
	cout << "Last name: " << ae.lname << endl;
}
void abstr_emp::data() const
{
	cout << "First name: " << fname << endl;
	cout << "Last name: " << lname << endl;
	cout << "Job: " << job << endl;
}
void abstr_emp::showAll() const
{
	cout << "\tEMPLOYEE\t" << endl;
	data();
}
void abstr_emp::get()
{
	cout << "Input first name: ";
	getline(cin,fname);
	cout << "Input last name: ";
	getline(cin,lname);
	cout << "Input job: ";
	getline(cin,job);
}
void abstr_emp::setAll()
{
	get();
}

void employee::showAll() const
{
	cout << "\tEMPLOYEE\t" << endl;
	data();
}
void employee::setAll()
{
	get();
}

void manager::data() const
{
	cout << "In charge of: " << inchargeof << endl;
}
void manager::showAll() const
{
	cout << "\tMANAGER\t" << endl;
	abstr_emp::data();
	data();
}
void manager::get()
{
	cout << "Input inchargeof: ";
	cin >> inchargeof;
	while(cin.get() != '\n')
		continue;
}
void manager::setAll()
{
	abstr_emp::get();
	get();
}

void fink::data() const
{
	cout << "Reports to: " << reportsto << endl;
}
void fink::showAll() const
{
	cout << "\tFINK\t" << endl;
	abstr_emp::data();
	data();
}
void fink::get()
{
	cout << "Input reports to: ";
	getline(cin,reportsto);
}
void fink::setAll()
{
	abstr_emp::get();
	get();
}
void highfink::showAll() const
{
	cout << "\tHIGHFINK\t" << endl;
	abstr_emp::data();
	manager::data();
	fink::data();
}
void highfink::setAll()
{
	abstr_emp::get();
	manager::get();
	fink::get();
}


