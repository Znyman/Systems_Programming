#include <iostream>
#include <cassert>
#include "VoxelModel.h"

using namespace std;

int main() {
	
	for (int i = 0; i < 64; i++)
	{
		assert(getIndex(getX(i), getY(i), getZ(i)) == i);
	}

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			for (int z = 0; z < 4; z++)
			{
				assert(getX(getIndex(x, y, z)) == x);
				assert(getY(getIndex(x, y, z)) == y);
				assert(getZ(getIndex(x, y, z)) == z);
			}
		}
		
	}
	
	cout << "Assertions completed successfully!" << endl;

	uint64_t emptyModel1 = emptyModel();
	cout << hex << "emptyModel1: 0x" << emptyModel1 << endl;

	uint64_t fullModel2 = fullModel();
	cout << "fullModel2: 0x" << fullModel2 << endl;

	uint64_t manipulatedModel = emptyModel1;
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			for (int z = 0; z < 4; z++)
			{
				if ((x + y + z) % 3 == 0)
				{
					manipulatedModel = toggleBit(manipulatedModel, x, y, z);
					cout << "manipulatedModel is now: #0x" << manipulatedModel << endl;
				}
				if ((x + y + z) % 5 == 0)
				{
					manipulatedModel = setBit(manipulatedModel, x, y, z);
					cout << "manipulatedModel is now: #0x" << manipulatedModel << endl;
				}
				if ((x + y + z) % 7 == 0)
				{
					manipulatedModel = clearBit(manipulatedModel, x, y, z);
					cout << "manipulatedModel is now: #0x" << manipulatedModel << endl;
				}
				
				cout << "The ";
				printf("%d", getIndex(x, y, z));
				cout << " bit is set to: " << getBit(manipulatedModel, x, y, z) << endl;
			}
		}
	}

	return 0;
}