#include <iostream>
#include <chrono>
#include <ctime>

void swap_value(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap_reference(int& a, int& b)
{
	int temp{ static_cast<int&&>(a) };
	a = static_cast<int&&>(b);
	b = static_cast<int&&>(temp);
}

void swap_pointer(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

struct pair
{
	int num1 = 5;
	int num2 = 10;
};

void swap_struct_value(pair p)
{
	int temp = p.num1;
	p.num1 = p.num2;
	p.num2 = temp;
}
void swap_struct_reference(pair &p)
{
	int temp{ static_cast<int&&>(p.num1) };
	p.num1 = static_cast<int&&>(p.num2);
	p.num2 = static_cast<int&&>(temp);
}
void swap_struct_pointer(pair *p)
{
	int temp = p->num1;
	p->num1 = p->num2;
	p->num2 = temp;
}

struct randomShit
{
	int theArray[100000];
};

int sumStructArrayReference(randomShit& r)
{
	int sum = 0;
	for (int i = 0; i < sizeof(r.theArray) / sizeof(r.theArray[0]); i++)
	{
		sum += r.theArray[i];
	}
	return sum;
}

int sumStructArrayValue(randomShit r)
{
	int sum = 0;
	for (int i = 0; i < sizeof(r.theArray) / sizeof(r.theArray[0]); i++)
	{
		sum += r.theArray[i];
	}
	return sum;
}

int main() {

	int x, y, z, sum;
	pair pair1;

	x = 1;
	y = 2;
	z = 3;

	std::cout << "Swap value before: " << "\nx: " << x << "\ny: " << y << "\nz: " << z << std::endl;
	swap_value(x, y);
	swap_value(y, z);
	std::cout << "Swap value after: " << "\nx: " << x << "\ny: " << y << "\nz: " << z << std::endl;

	std::cout << "Swap reference before: " << "\nx: " << x << "\ny: " << y << "\nz: " << z << std::endl;
	swap_reference(x, y);
	swap_reference(y, z);
	std::cout << "Swap reference after: " << "\nx: " << x << "\ny: " << y << "\nz: " << z << std::endl;

	std::cout << "Swap pointer before: " << "\nx: " << x << "\ny: " << y << "\nz: " << z << std::endl;
	swap_pointer(&x, &y);
	swap_pointer(&y, &z);
	std::cout << "Swap pointer after: " << "\nx: " << x << "\ny: " << y << "\nz: " << z << std::endl;

	std::cout << "Swap struct value before: " << "\nnum1: " << pair1.num1 << "\nnum2: " << pair1.num2 << std::endl;
	swap_struct_value(pair1);
	std::cout << "Swap struct value after: " << "\nnum1: " << pair1.num1 << "\nnum2: " << pair1.num2 << std::endl;

	std::cout << "Swap struct reference before: " << "\nnum1: " << pair1.num1 << "\nnum2: " << pair1.num2 << std::endl;
	swap_struct_reference(pair1);
	std::cout << "Swap struct reference after: " << "\nnum1: " << pair1.num1 << "\nnum2: " << pair1.num2 << std::endl;

	std::cout << "Swap struct pointer before: " << "\nnum1: " << pair1.num1 << "\nnum2: " << pair1.num2 << std::endl;
	swap_struct_reference(pair1);
	std::cout << "Swap struct pointer after: " << "\nnum1: " << pair1.num1 << "\nnum2: " << pair1.num2 << std::endl;

	randomShit r1;

	for (int i = 0; i < 100000; i++)
	{
		r1.theArray[i] = i;
		//std::cout << r1.theArray[i];
	}

	std::cout << "Pass by reference:" << std::endl;

	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();

	for (int i = 0; i < 10000; i++)
	{
		sum = sumStructArrayReference(r1);
	}

	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "Elapsed time: " << elapsed_seconds.count() << "s\n";

	std::cout << "sum: " << sum << std::endl;

	std::cout << "Pass by value:" << std::endl;

	start = std::chrono::system_clock::now();

	for (int i = 0; i < 10000; i++)
	{
		sum = sumStructArrayValue(r1);
	}

	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "Elapsed time: " << elapsed_seconds.count() << "s\n";

	std::cout << "sum: " << sum << std::endl;

	return 0;
}