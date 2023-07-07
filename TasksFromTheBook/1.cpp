#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <cstdlib>
#include <set>
#include <iterator>
#include <list>
#include <ctime>
#include <climits>
#include <memory>
#include <unistd.h>
#include <iomanip>
#include <cstring>
#include <utility>
#include <initializer_list>
using namespace std;
long double sum_values( char * b)
{
    return 0;
}
template <int> 
void sum_values(char a)
{
    return;
}
class A 
{
   public: 
     A(){cout << "A" << endl;};
    static void  show() {cout << "A" << endl;};
   protected:
     int data;
     private slots:
     int d;
};


 
int main(int argc, const char *argv[])
{
    using namespace std;
   // sry::A r;
    A a;
    A::show();
    return 0;
}
