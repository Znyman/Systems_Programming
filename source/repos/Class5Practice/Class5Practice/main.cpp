#include <iostream>
#include <string>
#include <cstdio>
#include <array>
#pragma warning(disable : 4996)

using namespace std;

struct myStruct1
{
	char a1;
	char a2;
	uint16_t num1;
	uint32_t num2;
	char a3;
};

struct myStruct2
{
	float num1;
	double num2;
	char b1;
	string s1;
};

struct myStruct3
{
	float num1;
	double num2;
	char b1;
	int num3;
};

struct myStruct4
{
	int num1[5];
	char a1[10];
	int num2;
};


int main() {
	std::cout << "My struct 1: " << sizeof(myStruct1) << " bytes" << endl;
	std::cout << "My struct 2: " << sizeof(myStruct2) << " bytes" << endl;
	std::cout << "My struct 3: " << sizeof(myStruct3) << " bytes" << endl;
	std::cout << "My struct 4: " << sizeof(myStruct4) << " bytes" << endl;

	FILE* fp = fopen("test.bin", "w+b");
	if (!fp)
	{
		perror("File opening failed");
		return EXIT_FAILURE;
	}

	myStruct1 manipulatedStruct[4];
	manipulatedStruct[0] = { 'a', 'b', 12, 16, 'c' };
	manipulatedStruct[1] = { 'd', 'e', 13, 17, 'f' };
	manipulatedStruct[2] = { 'g', 'h', 14, 18, 'i' };
	manipulatedStruct[3] = { 'j', 'k', 15, 19, 'l' };

	fwrite(&manipulatedStruct, sizeof(manipulatedStruct[0]), 4, fp);

	return 0;
}