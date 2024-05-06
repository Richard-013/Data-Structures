#include "MyVector.h"
#include <iostream>

MyVector::MyVector(size_t vectorLength)
{
	length = vectorLength;
	updateCapacity();

	createVector(&baseArray);

	setStart(&baseArray);
}

void MyVector::printVector()
{
	std::cout << "Length: " << length << std::endl;
	std::cout << "Capacity: " << capacity << std::endl;

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

bool MyVector::updateCapacity()
{
	if (length < capacity / 2)
	{
		return false;
	}

	while (length >= capacity / 2)
	{
		capacity = capacity * 2;
	}

	return true;
}

void MyVector::createVector(int** array)
{
	*array = (int*)realloc(*array, capacity * sizeof(int));
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

	*array = (int*)realloc(*array, length * sizeof(int));
}

void MyVector::setStart(int** array)
{
	start = *array;
}

void MyVector::setValueAtIndex(int value, int index)
{
	int* indexPointer = start;

	for (int i = 0; i < index; i++)
	{
		if (i == length)
		{
			// Throw an error if pointer leaves the acceptable range
			throw std::out_of_range("Index out of range");
		}

		indexPointer++;
	}

	*indexPointer = value;
}
