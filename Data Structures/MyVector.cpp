#include "MyVector.h"
#include <iostream>

MyVector::MyVector(size_t vectorLength)
{
	length = vectorLength;
}

void MyVector::resizeArray(int** array, size_t sizeChange, bool increaseSize)
{
	if (!increaseSize)
	{
		length -= sizeChange;
	}
	else
	{
		length += sizeChange;
	}

	*array = (int*)realloc(*array, length * sizeof(int));
}
