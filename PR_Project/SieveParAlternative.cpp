#include "SieveParAlternative.h"

std::string SieveParAlternative::name()
{
	return "Sieve Algorith, split range array";
}

int* SieveParAlternative::find(int min, int max, int* size)
{
    int dividersSize = sqrt(max) + 1;
    int arraySize = max - min;

    // Initialize array
    bool* array = new bool[arraySize];

    *size = 0;

    for (int i = 0; i < arraySize; i++)
    {
        array[i] = true;
    }

    bool* dividers = new bool[dividersSize];

    for (int i = 0; i < dividersSize; i++)
    {
        dividers[i] = true;
    }

    // Filter non-prime dividers
    for (int i = 2; i < sqrt(dividersSize); i++)
    {
        int j = i;
        while (j + i < dividersSize)
        {
            j += i;
            dividers[j] = false;
        }
    }


#pragma omp parallel
    {
        // Filter non-prime numbers
        int maxT = ParallelPrimeFinder::MAX_THREAD_NUM;
        int t = omp_get_thread_num();
        int minIndex = min + t * arraySize / maxT;
        int maxIndex = min + (t + 1) * arraySize / maxT;
        for (int i = 2; i < sqrt(maxIndex); i++)
        {
            if (dividers[i])
            {
                int j = i * ((minIndex - 1) / i);
                if (j < i)
                {
                    j += i;
                }
                while (j + i < maxIndex)
                {
                    j += i;
                    int index = j - min;
                    if (array[index])
                    {
                        array[index] = false;
                    }
                }
            }
        }
    }

    for (int i = 0; i < arraySize; i++)
    {
        if (array[i])
        {
            (*size)++;
        }
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
