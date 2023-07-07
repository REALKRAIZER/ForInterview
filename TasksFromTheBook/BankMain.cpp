#include <iostream>
#include "bank.h"
int main(int argc, char const *argv[])
{
	BankAccount Dima = {"Dima", "1", 500};
	Dima.show();
	Dima.deposite(200);
	Dima.show();
	return 0;
}