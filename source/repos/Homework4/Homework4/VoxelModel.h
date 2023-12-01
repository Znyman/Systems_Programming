#pragma once
#ifndef VoxelModel_h
#define VoxelModel_h

#include <stdint.h>

struct VoxelModel
{
	int xDimension, yDimension, zDimension;
	uint8_t* bitMap;
};

int getIndex(const VoxelModel& model, int x, int y, int z);//take the x, y, z coordinates and return which bit represents that voxel.
void getXYZ(const VoxelModel& model, int index, int& x, int& y, int& z);
VoxelModel allocateModel(int nx, int ny, int nz);//create a VoxelModel struct and initialize it to be an empty model with appropriate dimensions
void clearModel(VoxelModel& model);//set all the voxels in the model to off
void fillModel(VoxelModel& model);//set all the voxels in the model to on
void deleteModel(VoxelModel& model);//deallocate all heap memory and set the model's size to be 0, and data to be null.
int getByteNumber(int index);//return which byte in your dynamic array contains byte number index
uint8_t getBitNumber(int index);//return which bit in that byte corresponds to byte number index
bool getBit(VoxelModel model, int x, int y, int z);//return true if the bit for x, y, z is 1, and false if it's 0.
VoxelModel setBit(VoxelModel& model, int x, int y, int z);//returns a model that's the same as the parameter, except that the bit corresponding to x, y, z is set to 1.
VoxelModel clearBit(VoxelModel& model, int x, int y, int z);//same as setBit, but the bit for x, y, z should be set to 0
VoxelModel toggleBit(VoxelModel& model, int x, int y, int z);//same as set / clearBit, but the value of bit x, y, z should be "flipped."  If it is 1 in the parameter passed in, set it to 0, and vice versa.
VoxelModel addSphere(VoxelModel& model, float cx, float cy, float cz, float radius);
VoxelModel subtractSphere(VoxelModel& model, float cx, float cy, float cz, float radius);
VoxelModel toggleSphere(VoxelModel& model, float cx, float cy, float cz, float radius);

#endif // !VoxelModel_h