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
	bool isEmpty();

private:
	size_t length;
	size_t capacity = 16;

	bool updateCapacity();
	void createVector(int** array);
	void resizeVector(int** array, size_t sizeChange, bool increaseSize);
	void setStart(int** array);
	void setValueAtIndex(int value, int index);
};

