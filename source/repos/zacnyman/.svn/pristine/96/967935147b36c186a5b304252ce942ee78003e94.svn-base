#include "MyString.h"
#include <cstring>
#include <iostream>

MyString::MyString()
{
	string = new char[1];
	string[0] = '\0';
}

MyString::MyString(const MyString &input)
{
	const int length = strlen(input.string);
	this->string = new char[length+1];//+1 for \0 at end of string
	for (int i = 0; i < length; i++)
	{
		string[i] = input.string[i];
	}
	string[length] = '\0';
}

MyString::MyString(const char *input)
{
	int length = strlen(input);
	this->string = new char[length+1];//+1 for \0 at end of string
	for (int i = 0; i < length; i++)
	{
		string[i] = input[i];
	}
	string[length] = '\0';
}

MyString::~MyString()
{
	delete[] string;
	string = NULL;
}

MyString & MyString::operator=(const MyString &input)
{
	const int length = strlen(input.string);
	char* temp = new char[length+1];//+1 for \0 at end of string
	for (int i = 0; i < length; i++)
	{
		temp[i] = input.string[i];
	}
	temp[length] = '\0';
	delete[] this->string;
	string = temp;
	return *this;
}

size_t MyString::length() const
{
	return size_t();
}

const char * MyString::cString() const
{
	return this->string;
}
