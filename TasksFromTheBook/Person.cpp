#include "Person.h"
using std::cout;
using std::endl;
void Person::Data()
{
	cout << "Person`s name: ";
	cout << name << endl;
	cout << "Person`s surname: ";
	cout << surname << endl;
}
void Person::Data()
{
	Data();
}
void Gunslinger::Data()
{
	cout << "Gunslinger`s nutches: ";
	cout << nutchCount << endl;
}
void Gunslinger::Show()
{
	Person::Data();
	Data();
}