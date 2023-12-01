#include "VoxelModel.h"
#include <cassert>
#include <stdint.h>
#include <iostream>
#include <cmath>


//take the x, y, z coordinates and return which bit represents that voxel.
int getIndex(const VoxelModel & model, int x, int y, int z)
{
	int index = 0;

	index += model.yDimension * model.zDimension * x;
	index += model.zDimension * y;
	index += z;

	return index;
}
void getXYZ(const VoxelModel & model, int index, int & x, int & y, int & z)
{
	x = index / (model.yDimension * model.zDimension);
	y = (index % (model.yDimension * model.zDimension)) / model.zDimension;
	z = index % (model.zDimension);
}
VoxelModel allocateModel(int nx, int ny, int nz)
{
	if (nx < 1 || ny < 1 || nz < 1)
	{
		perror("ERROR: Please use dimensions greater than 0 for 3D modeling.");
	}
	assert(nx > 0, ny > 0, nz > 0);
	VoxelModel model{ nx, ny, nz };
	model.bitMap = new uint8_t[nx*ny*nz];
	return model;
}
void clearModel(VoxelModel & model)
{
	int length = model.xDimension * model.yDimension * model.zDimension;
	for (int i = 0; i < length; i++)
	{
		model.bitMap[i] = 0;
	}
}
void fillModel(VoxelModel & model)
{
	int length = model.xDimension * model.yDimension * model.zDimension;
	for (int i = 0; i < length; i++)
	{
		model.bitMap[i] = 0xFF;
	}
}
void deleteModel(VoxelModel & model)
{
	model.xDimension = NULL;
	model.yDimension = NULL;
	model.zDimension = NULL;
	delete[] model.bitMap;
	model.bitMap = NULL;
}
int getByteNumber(int index)
{
	return index / 8;
}
uint8_t getBitNumber(int index)
{
	return index % 8;
}
//return true if the bit for x, y, z is 1, and false if it's 0.
bool getBit(VoxelModel model, int x, int y, int z)
{
	int index = getIndex(model, x, y, z);
	int byteNumber = getByteNumber(index);
	uint8_t shifter = getBitNumber(index);
	uint8_t checker = 1 << shifter;
	uint8_t result = model.bitMap[byteNumber] & checker;
	return result >> shifter;
}
//returns a model that's the same as the parameter, except that the bit corresponding to x, y, z is set to 1.
VoxelModel setBit(VoxelModel & model, int x, int y, int z)
{
	int index = getIndex(model, x, y, z);
	int byteNumber = getByteNumber(index);
	uint8_t shifter = getBitNumber(index);
	uint8_t setter = 1 << shifter;
	model.bitMap[byteNumber] |= setter;
	return model;
}
//same as setBit, but the bit for x, y, z should be set to 0
VoxelModel clearBit(VoxelModel & model, int x, int y, int z)
{
	int index = getIndex(model, x, y, z);
	int byteNumber = getByteNumber(index);
	uint8_t shifter = getBitNumber(index);
	uint8_t clear = 1 << shifter;
	clear = ~clear;
	model.bitMap[byteNumber] &= clear;
	return model;
}
//same as set / clearBit, but the value of bit x, y, z should be "flipped."  If it is 1 in the parameter passed in, set it to 0, and vice versa.
VoxelModel toggleBit(VoxelModel & model, int x, int y, int z)
{
	int index = getIndex(model, x, y, z);
	int byteNumber = getByteNumber(index);
	uint8_t shifter = getBitNumber(index);
	uint8_t toggle = 1 << shifter;
	model.bitMap[byteNumber] ^= toggle;
	return model;
}

VoxelModel addSphere(VoxelModel & model, float cx, float cy, float cz, float radius)
{
	int x = 0, y = 0, z = 0;
	int length = model.xDimension * model.yDimension * model.zDimension * 8;
	for (int i = 0; i < length; i++)
	{
		getXYZ(model, i, x, y, z);
		if ((pow((x - cx), 2) + pow((y - cy), 2) + pow((z - cz), 2)) < pow(radius, 2))
		{
			setBit(model, x, y, z);
		}
	}
	return model;
}

VoxelModel subtractSphere(VoxelModel & model, float cx, float cy, float cz, float radius)
{
	int x = 0, y = 0, z = 0;
	int length = model.xDimension * model.yDimension * model.zDimension * 8;
	for (int i = 0; i < length; i++)
	{
		getXYZ(model, i, x, y, z);
		if ((pow((x - cx), 2) + pow((y - cy), 2) + pow((z - cz), 2)) < pow(radius, 2))
		{
			clearBit(model, x, y, z);
		}
	}
	return model;
}

VoxelModel toggleSphere(VoxelModel & model, float cx, float cy, float cz, float radius)
{
	int x = 0, y = 0, z = 0;
	int length = model.xDimension * model.yDimension * model.zDimension * 8;
	for (int i = 0; i < length; i++)
	{
		getXYZ(model, i, x, y, z);
		if ((pow((x - cx), 2) + pow((y - cy), 2) + pow((z - cz), 2)) < pow(radius, 2))
		{
			toggleBit(model, x, y, z);
		}
	}
	return model;
}
