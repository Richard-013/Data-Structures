#pragma once

#include <cstdlib>

class MyVector
{
public:
	int* baseArray = (int*) std::malloc(sizeof(int) * 1);
	int* start;

	MyVector(size_t vectorLength);
	void printVector();
	size_t getSize();

private:
	size_t length;

	void resizeArray(int** array, size_t sizeChange, bool increaseSize);
	void createVector(int** array);
	void resizeVector(int** array, size_t sizeChange, bool increaseSize);
	void setStart(int** array);
};

