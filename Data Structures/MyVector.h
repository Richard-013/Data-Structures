#pragma once

#include <cstdlib>

class MyVector
{
public:
	int* baseArray = (int*) std::malloc(sizeof(int) * 1);

	MyVector(size_t vectorLength);

private:
	size_t length;

	void resizeArray(int** array, size_t sizeChange, bool increaseSize);
};

