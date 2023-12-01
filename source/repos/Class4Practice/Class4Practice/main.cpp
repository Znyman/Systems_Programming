#include <iostream>

int main() {
	
	int8_t x = 4;
	int16_t y = 8;
	int64_t z = 12;

	int8_t* a = &x;
	int16_t* b = &y;
	int64_t* c = &z;

	std::cout << sizeof(a) << sizeof(x) << sizeof(b) << sizeof(y) << sizeof(c) << sizeof(z) << '\n';

	printf("%p", &x);
	std::cout << '\n';
	printf("%p", a);
	std::cout << '\n';
	printf("%p", &a);
	std::cout << '\n';


	return 0;
}