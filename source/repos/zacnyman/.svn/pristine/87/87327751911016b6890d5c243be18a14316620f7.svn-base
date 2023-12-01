#include <iostream>
#include "MyString.h"

int main(int argc, const char * argv[])
{
	MyString s;
	std::cout << "Empty: '" << s.cString() << "'\n";
	s = "hello";
	std::cout << "After operator=: '" << s.cString() << "'\n";
	{
		MyString t(s);
		std::cout << "After copy: '" << t.cString() << "'\n";
		s = t;
	}

	MyString m(" world");
	std::cout << "After constructor: '" << m.cString() << "'\n";
	m = s;
	std::cout << "After operator=: '" << m.cString() << "'\n";
	m = m;
	std::cout << "After operator=: '" << m.cString() << "'\n";

	std::cout << "Beginning of Heap testing." << std::endl;

	MyString* p = new MyString;
	std::cout << "Empty: '" << p->cString() << "'\n";

	MyString* q = new MyString("TEST1");
	std::cout << "After constructor: '" << q->cString() << "'\n";

	{
		MyString* r = new MyString(*q);
		std::cout << "After copy: '" << r->cString() << "'\n";
		delete r;
		r = NULL;
	}

	*p = *q;
	std::cout << "After operator=: '" << p->cString() << "'\n";

	*p = *p;
	std::cout << "After operator=: '" << p->cString() << "'\n";

	delete q;
	delete p;
	q = NULL;
	p = NULL;

	return 0;
}