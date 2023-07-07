#include <iostream>
#include <cstring>
class A {
   int i;
};

class B: virtual A {
};

class C: virtual A {
};


class D: B, C {
};


int main () {
	D d;
   B * b = &d;
}