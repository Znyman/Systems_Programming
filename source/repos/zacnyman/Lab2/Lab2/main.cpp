#include <iostream>
#include <stdint.h>

int main() {

	std::cout << "Size of bool: " << sizeof(bool) << '\n';
	std::cout << "Size of char: " << sizeof(char) << '\n';
	std::cout << "Size of short: " << sizeof(short) << '\n';
	std::cout << "Size of int: " << sizeof(int) << '\n';
	std::cout << "Size of long: " << sizeof(long) << '\n';
	std::cout << "Size of long long: " << sizeof(long long) << '\n';
	std::cout << "Size of float: " << sizeof(float) << '\n';
	std::cout << "Size of double: " << sizeof(double) << '\n';
	std::cout << "Size of long double: " << sizeof(long double) << '\n';

	std::cout << "Size of int8_t: " << sizeof(int8_t) << '\n';
	std::cout << "Size of int16_t: " << sizeof(int16_t) << '\n';
	std::cout << "Size of int32_t: " << sizeof(int32_t) << '\n';
	std::cout << "Size of int64_t: " << sizeof(int64_t) << '\n';

	int16_t small;
	std::cout << "Enter a int16_t: ";
	std::cin >> small;
	std::cout << "You entered " << small << " which is " << std::hex << small << " in hex" << '\n';

	int32_t medium;
	std::cout << "Enter a int32_t: ";
	std::cin >> medium;
	std::cout << "You entered " << std::dec << medium << " which is " << std::hex << medium << " in hex" << '\n';

	int64_t large;
	std::cout << "Enter a int64_t: ";
	std::cin >> large;
	std::cout << "You entered " << std::dec << large << " which is " << std::hex << large << " in hex" << '\n';

	std::cout << std::dec << "Signed overflow:\n";

	int8_t a = INT8_MAX;
	std::cout << int{ a } << '\n';
	a += 1;
	std::cout << int{ a } << '\n';

	int16_t b = INT16_MAX;
	std::cout << b << '\n';
	b += 1;
	std::cout << b << '\n';

	int32_t c = INT32_MAX;
	std::cout << c << '\n';
	c += 1;
	std::cout << c << '\n';

	int64_t d = INT64_MAX;
	std::cout << d << '\n';
	d += 1;
	std::cout << d << '\n';

	std::cout << "Unsigned overflow:\n";

	uint8_t ua = UINT8_MAX;
	std::cout << int{ ua } << '\n';
	ua += 1;
	std::cout << int{ ua } << '\n';

	uint16_t ub = UINT16_MAX;
	std::cout << ub << '\n';
	ub += 1;
	std::cout << ub << '\n';

	uint32_t uc = UINT32_MAX;
	std::cout << uc << '\n';
	uc += 1;
	std::cout << uc << '\n';

	uint64_t ud = UINT64_MAX;
	std::cout << ud << '\n';
	ud += 1;
	std::cout << ud << '\n';


	uint32_t umax32 = 0xffffffff;
	uint32_t umin32 = 0;
	uint64_t umax64 = 0xffffffffffffffff;
	uint64_t umin64 = 0;

	std::cout << "umax32: " << std::dec << umax32 << '\n';
	std::cout << "umin32: " << std::dec << umin32 << '\n';
	std::cout << "umax64: " << std::dec << umax64 << '\n';
	std::cout << "umin64: " << std::dec << umin64 << '\n';

	int32_t max32 = 0x7fffffff;
	int32_t min32 = 0x80000000;
	int64_t max64 = 0x7fffffffffffffff;
	int64_t min64 = 0x8000000000000000;

	std::cout << "max32: " << std::dec << max32 << '\n';
	std::cout << "min32: " << std::dec << min32 << '\n';
	std::cout << "max64: " << std::dec << max64 << '\n';
	std::cout << "min64: " << std::dec << min64 << '\n';

	int uninitINT;
	float uninitFLOAT;
	double uninitDOUBLE;

	//std::cout << uninitINT;
	//std::cout << uninitFLOAT;
	//std::cout << uninitDOUBLE;
}