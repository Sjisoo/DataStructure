#include <stdio.h>

int arraySize;
int arrayCapacity;
int* Array;

int main()
{
    int newValue;

    if (arraySize == arrayCapacity)
    {
        append(newValue);
    }
}

void append(int newValue)
{
    int newCapacity = arrayCapacity + 1;
    int *newArray = new int[newCapacity];

    int arrayIndex;
    for (arrayIndex = 0; arrayIndex < arraySize; arrayIndex++)
    {
        newArray[arrayIndex] = Array[arrayIndex];
    }

    if (Array)
    {
        delete [] Array;
    }
    Array = newArray;
    arrayCapacity = newCapacity;

    Array[arraySize++] = newValue;
}