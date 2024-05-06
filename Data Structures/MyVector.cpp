#include "MyVector.h"
#include <iostream>

MyVector::MyVector(size_t vectorLength)
{
	length = vectorLength;

	if (length != 1)
	{
		createVector(&baseArray);
	}

	setStart(&baseArray);

}

void MyVector::printVector()
{
	for (int i = 0; i < length; i++)
	{
		std::cout << "Element " << i << ": " << baseArray[i];

		if (i + 1 < length)
		{
			std::cout << ", ";
		}
	}

	std::cout << std::endl;
}

size_t MyVector::getSize()
{
	return length;
}

void MyVector::createVector(int** array)
{
	*array = (int*)realloc(*array, length * sizeof(int));
}

void MyVector::resizeVector(int** array, size_t sizeChange, bool increaseSize)
{
	if (!increaseSize)
	{
		length -= sizeChange;
	}
	else
	{
		length += sizeChange;
	}

	*array = (int*) realloc(*array, length * sizeof(int));
}

void MyVector::setStart(int** array)
{
	start = *array;
}

}
