#include "Foo.h"

Foo::Foo(int x = 1, int y = 2, int z = 3)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
void Foo::setX(int x = 1)
{
	this->x = x;
}
int Foo::product()
{
	return this->x * this->y;
}
void Foo::init(int x = 1, int y = 2, int z = 3)
{
	this->x = x;
	this->y = y;
	this->z = z;
}