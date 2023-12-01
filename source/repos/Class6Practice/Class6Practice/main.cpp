#include <iostream>

int main() {
	int stackArray[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };//first way to initialize values in the array
	for (int i = 0; i < 10; i++)//second way to initiailize values in the array
	{
		stackArray[i] = i;
		std::cout << stackArray[i];
	}
	int* heapArray = new int[10];
	for (int i = 0; i < 10; i++)
	{
		heapArray[i] = i;
		std::cout << heapArray[i];
	}
	//code that uses heapArray
	delete[]heapArray;

	return 0;
}