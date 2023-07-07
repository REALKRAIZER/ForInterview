#include <cstring>
#include <vector>
#include "emp.h"
using std::cin;
using std::cout;
using std::endl;
 
int main(void)
{
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.showAll();
    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.showAll();
    fink fi("Matt", "Oggs", "Oiler", "JunoBarr");
    cout << fi << endl;
    fi.showAll();
    highfink hf(ma, "Curly Kew"); // укомплектовано?
    hf.showAll() ;
    cout << "Press a key for next phase:\n";
    cin.get() ;
    highfink hf2;
    hf2.setAll();
    cout << "Using an abstr_emp * pointer:\n";
    const int size{4};
    std::vector <abstr_emp*> tri{&em, &fi, &hf, &hf2};
    for (int i = 0; i < size; i++)
    {
        tri[i]->showAll() ;
    }
}