#include <iostream>
#include "Foo.h"

int main() {
	
	Foo f1;
	Foo f2(10);
	Foo* f3 = new Foo(20, 40, 60);

	return 0;
}