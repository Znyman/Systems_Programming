#include <iostream>
#include <string>
#include "pair.h"
using std::string;

struct Foo
{
	int x;
};

int main(int argc, const char * argv[])
{
	Pair<int, int> p1(5, 6);
	p1.PrintPair();

	Pair<int, string>* p2 = new Pair<int, string>(1, "fuck");
	p2->PrintPair();

	/*Foo temp;
	temp.x = 4;
	Pair<int, Foo> p3(5, temp);*/
	//p3.PrintPair();//throws error on printing struct foo

	return 0;
}