#pragma once
#include <stdint.h>

uint8_t getIndex(int x, int y, int z);//take the x, y, z coordinates (which could each be 0, 1, 2, or 3), and return which bit represents that voxel (the result will be in the range [0, 63]).
/*
These 3 functions are the inverse of getIndex. You can test this with something like the following:
for all i between 0 and 63: assert(getIndex(getX(i), getY(i), getZ(i)) == i) and also for all
x between 0..3, y between 0..3, z between 0..3: assert(getX(getIndex(x,y,z)) == x), and similarly for y and z.
*/
uint8_t getX(uint8_t index);
uint8_t getY(uint8_t index);
uint8_t getZ(uint8_t index);

uint64_t emptyModel();//return a model with all bits set to 0
uint64_t fullModel();//return a model with all bits set to 1
bool getBit(uint64_t model, int x, int y, int z);//return true if the bit for x, y, z is 1, and false if it's 0.
uint64_t setBit(uint64_t model, int x, int y, int z);//returns a model that's the same as the parameter, except that the bit corresponding to x, y, z is set to 1.
uint64_t clearBit(uint64_t model, int x, int y, int z);//same as setBit, but the bit for x, y, z should be set to 0
uint64_t toggleBit(uint64_t model, int x, int y, int z);//same as set / clearBit, but the value of bit x, y, z should be "flipped."  If it is 1 in the parameter passed in, set it to 0, and vice versa.

