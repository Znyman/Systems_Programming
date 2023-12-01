#include <iostream>
#include <array>

int main() {

	int numbers[10];
	std::cout << "Please input " << (sizeof(numbers) / sizeof(*numbers)) << " numbers\n";

	//insert numbers into aray
	int x;
	for (int i = 0; i < (sizeof(numbers) / sizeof(*numbers)); i++)
	{
		std::cout << "Number " << i + 1 << ": ";
		std::cin >> x;
		numbers[i] = x;
	}

	//print numbers before sort
	std::cout << "Numbers before sort: ";
	for (int i = 0; i < (sizeof(numbers) / sizeof(*numbers)); i++)
	{
		std::cout << " " << numbers[i];
	}
	std::cout << '\n';

	//sort the array
	for (int i = 1; i < (sizeof(numbers) / sizeof(*numbers)); i++)
	{
		int temp = numbers[i];
		int j = i - 1;
		while (j >= 0 && numbers[j] > temp)
		{
			numbers[j + 1] = numbers[j];
			j--;
		}
		numbers[j + 1] = temp;
	}

	std::cout << "Numbers after sort: ";
	for (int i = 0; i < (sizeof(numbers) / sizeof(*numbers)); i++)
	{
		std::cout << " " << numbers[i];
	}
	std::cout << '\n';

	return 0;
}