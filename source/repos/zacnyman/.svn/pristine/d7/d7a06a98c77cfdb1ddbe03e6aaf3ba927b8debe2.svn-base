#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cassert>
#include "surfaceExtraction.hpp"

using std::cout;
using std::endl;
using std::hex;

int main()
{
	VoxelModel model1 = allocateModel(4, 3, 2);
	int totalBytes = model1.xDimension * model1.yDimension * model1.zDimension;
	int totalBits = model1.xDimension * model1.yDimension * model1.zDimension * 8;
	cout << "There are " << totalBytes << " uint8_t's in model1 which means there are " <<
		totalBits << " bits in model1. " << endl;
	//scoped to separate this x, y, z from the x, y, z in the for loops below.
	int x, y, z;

	for (int i = 0; i < totalBits; i++)
	{
		getXYZ(model1, i, x, y, z);
		assert(getIndex(model1, x, y, z) == i);
	}
	cout << "Assertions passed! Get index and getXYZ are working correctly." << endl;

	fillModel(model1);
	for (int i = 0; i < totalBits; i++)
	{
		getXYZ(model1, i, x, y, z);
		assert(getBit(model1, x, y, z) == 1);
	}
	cout << "Assertions passed! Every bit in the bit map is set to 1 after calling fill model.\n" <<
		"This implies that getByteNumber and getBitNumber are also working correctly since getBit uses these methods."
		<< endl;

	clearModel(model1);
	for (int i = 0; i < totalBits; i++)
	{
		getXYZ(model1, i, x, y, z);
		assert(getBit(model1, x, y, z) == 0);
	}
	cout << "Assertions passed! Every bit in the bit map is set to 0 after calling clear model." << endl;

	hex;
	fillModel(model1);

	for (int i = 0; i < totalBits; i++)
	{
		getXYZ(model1, i, x, y, z);
		if ((x + y + z) % 3 == 0)
		{
			model1 = toggleBit(model1, x, y, z);

			cout << "model1 is now: #0x";
			for (int i = totalBytes - 1; i >= 0; i--)
			{
			printf("%X", model1.bitMap[i]);
			}
			cout << endl;

			cout << "The ";
			printf("%d", getIndex(model1, x, y, z));
			cout << " bit was toggled to: " << getBit(model1, x, y, z) << endl;
		}
		if ((x + y + z) % 5 == 0)
		{
			model1 = setBit(model1, x, y, z);

			cout << "model1 is now: #0x";
			for (int i = totalBytes - 1; i >= 0; i--)
			{
			printf("%X", model1.bitMap[i]);
			}
			cout << endl;

			cout << "The ";
			printf("%d", getIndex(model1, x, y, z));
			cout << " bit was set to: " << getBit(model1, x, y, z) << endl;
		}
		if ((x + y + z) % 7 == 0)
		{
			model1 = clearBit(model1, x, y, z);

			cout << "model1 is now: #0x";
			for (int i = totalBytes - 1; i >= 0; i--)
			{
				printf("%X", model1.bitMap[i]);
			}
			cout << endl;

			cout << "The ";
			printf("%d", getIndex(model1, x, y, z));
			cout << " bit was cleared to: " << getBit(model1, x, y, z) << endl;
		}
	}

	cout << "Toggle, set, and clear bit functions are working properly." << endl;

	writeSTL(model1, "random1.stl");
	deleteModel(model1);
	assert(model1.xDimension == NULL, model1.yDimension == NULL, model1.zDimension == NULL, model1.bitMap == NULL);
	cout << "Assertion passed! model1 has been successfully cleared and deleted." << endl;

	VoxelModel smallCube = allocateModel(10, 10, 10);
	clearModel(smallCube);
	smallCube.bitMap[0] = 0x10;
	smallCube = addSphere(smallCube, 5, 5, 5, 3);
	writeSTL(smallCube, "smallCube.stl");
	deleteModel(smallCube);

	VoxelModel boobs = allocateModel(100, 100, 100);
	clearModel(boobs);
	boobs = addSphere(boobs, 25, 25, 25, 25);
	boobs = addSphere(boobs, 70, 25, 25, 25);
	writeSTL(boobs, "boobs.stl");
	deleteModel(boobs);

	VoxelModel deathStar = allocateModel(50, 50, 50);
	clearModel(deathStar);
	deathStar = addSphere(deathStar, 10, 10, 10, 7);
	deathStar = toggleSphere(deathStar, 30, 30, 30, 20);
	writeSTL(deathStar, "deathStar.stl");
	deathStar = subtractSphere(deathStar, 30, 30, 30, 20);
	writeSTL(deathStar, "planetaryDestruction.stl");
	deathStar = toggleSphere(deathStar, 10, 10, 10, 7);
	writeSTL(deathStar, "deathStarLeaves.stl");
	deleteModel(deathStar);

	return 0;
}