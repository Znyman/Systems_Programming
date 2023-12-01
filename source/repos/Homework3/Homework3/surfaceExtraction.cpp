//
//  surfaceExtraction.cpp
//  Homework3
//
//  Created by Ben Jones on 1/6/17.
//  Copyright © 2017 Ben Jones. All rights reserved.
//
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cassert>
#include "surfaceExtraction.hpp"
#include "VoxelModel.h"

using std::cout;
using std::endl;


inline void fillPlane(int a1, int a2, int b1, int b2, int c, int cInd, Triangle& t1, Triangle& t2){
    t1.v1[cInd] = c;
    t2.v1[cInd] = c;
    t1.v2[cInd] = c;
    t2.v2[cInd] = c;
    t1.v3[cInd] = c;
    t2.v3[cInd] = c;
    int aInd = (cInd +1) % 3;
    int bInd = (cInd +2) % 3;
    
    t1.v1[aInd] = a1;
    t1.v2[aInd] = a2;
    t1.v3[aInd] = a2;
    
    t2.v1[aInd] = a1;
    t2.v2[aInd] = a2;
    t2.v3[aInd] = a1;
    
    t1.v1[bInd] = b1;
    t1.v2[bInd] = b1;
    t1.v3[bInd] = b2;
    
    t2.v1[bInd] = b1;
    t2.v2[bInd] = b2;
    t2.v3[bInd] = b2;
    
}

void extractFace(int x, int y, int z, FaceType face, Triangle& t1, Triangle& t2){
    for(int i= 0; i < 3; i++){
        t1.normal[i] = 0;
        t2.normal[i] = 0;
    }
    switch(face){
        case NX:
            t1.normal[0] = -1;
            t2.normal[0] = -1;
            fillPlane(y + 1, y, z, z+1, x, 0, t1, t2);
            break;
        case NY:
            t1.normal[1] = -1;
            t2.normal[1] = -1;
            fillPlane(z + 1, z, x, x+1, y, 1, t1, t2);
            break;
        case NZ:
            t1.normal[2] = -1;
            t2.normal[2] = -1;
            fillPlane(x + 1, x, y, y + 1, z, 2, t1, t2);
            break;
        case PX:
            t1.normal[0] = 1;
            t2.normal[0] = 1;
            fillPlane(y, y + 1, z, z +1, x + 1, 0, t1, t2);
            break;
        case PY:
            t1.normal[1] = 1;
            t2.normal[1] = 1;
            fillPlane(z, z + 1, x, x + 1, y + 1, 1, t1, t2);
            break;
        case PZ:
            t1.normal[2] = 1;
            t2.normal[2] = 1;
            fillPlane(x, x +1, y, y + 1, z + 1, 2, t1, t2);
            break;
    }
}

void checkTriangles(Triangle* t)
{
	for (int k = 0; k < 3; k++)
	{
		cout << "Normal: " << t[0].normal[k] << endl;
		cout << "v1: " << t[0].v1[k] << endl;
		cout << "v2: " << t[0].v2[k] << endl;
		cout << "v3: " << t[0].v3[k] << endl;
	}
}

void writeTriangles(FaceType face, FILE* filePointer, int i)
{
	Triangle tri1[1];
	Triangle tri2[1];
	int currentWriteStatus;
	/*cout << "Triangle 1 before: " << endl;
	checkTriangles(tri1);
	cout << "Triangle 2 before: " << endl;
	checkTriangles(tri2);*/
	extractFace(getX(i), getY(i), getZ(i), face, tri1[0], tri2[0]);
	/*cout << "Triangle 1 after: " << endl;
	checkTriangles(tri1);
	cout << "Triangle 2 after: " << endl;
	checkTriangles(tri2);
	cout << "Size of triangle 1: " << sizeof(tri1[0]) << endl;
	cout << "Size of triangle 2: " << sizeof(tri2[0]) << endl;*/
	currentWriteStatus = fwrite(tri1, 50, 1, filePointer);
	assert(currentWriteStatus == 1);
	currentWriteStatus = fwrite(tri2, 50, 1, filePointer);
	assert(currentWriteStatus == 1);
}

void writeSTL(uint64_t model, const char* filename)
{
	FILE* filePointer = fopen(filename, "w+b");
	if (!filePointer)
	{
		perror("File opening failed");
		return;
	}
	char header[80] = { 0 };
	int currentSeekStatus, currentWriteStatus, currentReadStatus;
	uint32_t numTriangles[1] = { 0 };
	currentWriteStatus = fwrite(header, 1, sizeof(header), filePointer);
	assert(currentWriteStatus == sizeof(header));
	cout << "Header successfully written!" << endl;

	currentWriteStatus = fwrite(numTriangles, sizeof(numTriangles), 1, filePointer);
	assert(currentWriteStatus == 1);

	for (int i = 0; i < 64; i++)
	{
		if (getBit(model, getX(i), getY(i), getZ(i)))
		{
			//X axis
			if (!getBit(model, getX(i) - 1, getY(i), getZ(i)))
			{
				FaceType face = NX;
				writeTriangles(face, filePointer, i);
				numTriangles[0] += 2;
			}
			if (!getBit(model, getX(i) + 1, getY(i), getZ(i)))
			{
				FaceType face = PX;
				writeTriangles(face, filePointer, i);
				numTriangles[0] += 2;
			}
			//Y axis
			if (!getBit(model, getX(i), getY(i) - 1, getZ(i)))
			{
				FaceType face = NY;
				writeTriangles(face, filePointer, i);
				numTriangles[0] += 2;
			}
			if (!getBit(model, getX(i), getY(i) + 1, getZ(i)))
			{
				FaceType face = PY;
				writeTriangles(face, filePointer, i);
				numTriangles[0] += 2;
			}
			//Z axis
			if (!getBit(model, getX(i), getY(i), getZ(i) - 1))
			{
				FaceType face = NZ;
				writeTriangles(face, filePointer, i);
				numTriangles[0] += 2;
			}
			if (!getBit(model, getX(i), getY(i), getZ(i) + 1))
			{
				FaceType face = PZ;
				writeTriangles(face, filePointer, i);
				numTriangles[0] += 2;
			}
		}
	}
	currentSeekStatus = fseek(filePointer, 80, SEEK_SET);
	assert(currentSeekStatus == 0);
	currentWriteStatus = fwrite(numTriangles, sizeof(numTriangles), 1, filePointer);
	assert(currentWriteStatus == 1);
	cout << numTriangles[0] << " triangles successfully written to " << filename << "!" << endl;
	fclose(filePointer);
}