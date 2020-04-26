#include "Naive.h"

std::string Naive::name()
{
    return "Naive Algorithm";
}

int* Naive::find(int min, int max, int* size)
{
    int arraySize = max - min;

    bool* array = new bool[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        array[i] = checkPrime(min + i);
    }

    *size = 0;

    for (int i = 0; i < arraySize; i++)
    {
        if (array[i])
            (*size)++;
    }

    int* result = new int[*size];
    int j = 0;
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i])
            result[j++] = min + i;
    }

    // Clean up
    delete[] array;

    return result;
}