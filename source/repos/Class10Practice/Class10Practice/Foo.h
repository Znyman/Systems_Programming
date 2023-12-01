#pragma once
#ifndef Foo_hpp
#define Foo_hpp

#include <stdio.h>

class Foo
{
public:
	Foo(int x = 1, int y = 2, int z = 3);
	void setX(int x = 1);
	int product();
	void init(int x = 1, int y = 2, int z = 3);
private:
	int x;
	int y;
	int z;
};

#endif /*Foo_hpp*/