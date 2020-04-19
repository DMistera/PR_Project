#include "SieveParEverything.h"

std::string SieveParEverything::name()
{
	return "Sieve Algorith, maximum parallelization";
}

int* SieveParEverything::find(int min, int max, int* size)
{
    int dividersSize = sqrt(max) + 1;
    int arraySize = max - min;

    // Initialize array
    bool* array = new bool[arraySize];
    bool* dividers = new bool[dividersSize];

    *size = 0;

#pragma omp parallel
{

    #pragma omp for
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = true;
    }

    // Filter non-prime dividers
    int maxI = sqrt(dividersSize);
    #pragma omp for schedule(guided)
    for (int i = 2; i < maxI; i++)
    {
        int j = i;
        while (j + i < dividersSize)
        {
            j += i;
            dividers[j] = false;
        }
    }

    // Filter non-prime numbers
    #pragma omp for schedule(guided)
    for (int i = 2; i < dividersSize; i++)
    {
        if (dividers[i])
        {
            int j = i * floor((min - 1) / i);
            while (j + i < max)
            {
                j += i;
                int index = j - min;
                array[index] = false;
            }
        }
    }

    // Count all prime numbers
    int sum = 0;
    #pragma omp for
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i])
        {
            sum++;
        }
    }

    #pragma omp atomic
    *size += sum;
}
    // Insert all prime numbers into an array
    int* result = new int[*size];
    int j = 0;
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i])
        {
            result[j++] = min + i;
        }
    }


    // Clean up
    delete[] array;
    delete[] dividers;

    return result;
}
