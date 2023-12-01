#include <iostream>

template <typename T> 
bool foo(const T candidate)
{
	if (candidate < static_cast<T>(2))
	{
		return false;
	}
	else if	(candidate == static_cast<T>(2) || candidate == static_cast<T>(3))
}

int main() {
	
	foo<int>(5);

	return 0;
}