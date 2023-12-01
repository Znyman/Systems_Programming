#include <iostream>
using std::cout;
using std::endl;

int crashStack(int x)
{
	if (x == 0)
	{
		return 1;
	}
	return crashStack(x+1);
}

char* reverseString(const char *input)
{
	if (input == NULL)
	{
		char* output = new char[1];
		cout << "Passed null value.";
		output[0] = '\0';
		return output;
	}
	else if (input[0] == '\0')
	{
		char* output = new char[1];
		cout << "Passed empty value.";
		output[0] = '\0';
		return output;
	}
	int length = strlen(input);
	char* output = new char[sizeof(input)];
	char temp;
	for (int i = 0; i < length; i++)
	{
		output[i] = input[length - i - 1];
	}
	output[length] = '\0';
	return output;
}

int main() {

	cout << "This method will cause a stack overflow." << endl;
	int y = crashStack(1);
	cout << y << endl;

	const char* h1 = "Hello World";
	cout << h1 << endl;
	char* result1 = reverseString(h1);
	cout << result1 << endl;

	const char* h2 = "";
	char* result2 = reverseString(h2);
	cout << result2 << endl;

	const char* h3 = NULL;
	char* result3 = reverseString(h3);
	cout << result3 << endl;

	cout << h1 << endl;
	char* result4 = reverseString(h1);
	cout << result4 << endl;

	delete[] result1;
	result1 = NULL;
	delete[] result2;
	result2 = NULL;
	delete[] result3;
	result3 = NULL;
	delete[] result4;
	result4 = NULL;

	return 0;
}