#include <iostream>
#include "Lab8Header.h"

using std::cout;
using std::endl;
using std::cin;
using std::hex;
using std::dec;



int main() {

	ReadAndPrint<int>("int");//Not necessary to explicity identify type other than for printed statement
	//ReadAndPrint<double>("double");//Outputs decimal value for hex
	//ReadAndPrint<float>("float");//Outputs decimal value for hex
	//ReadAndPrint<pistachio>("pistachio");//Doesn't work; throws: error C2679: binary '<<': no operator found which takes a right-hand operand of type 'pistachio' (or there is no acceptable conversion)
	//<int*>("int array");//Doesn't work; throws: error C2678: binary '>>': no operator found which takes a left-hand operand of type 'std::istream' (or there is no acceptable conversion)

}