#include "SieveParDividers2.h"

std::string SieveParDividers2::name()
{
	return "Sieve Algorith, parallel finding of primes in given range, separated dividers2";
}

int* SieveParDividers2::find(int min, int max, int* size)
{
    int arraySize = max - min;

    // Initialize array
    bool* array = new bool[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        array[i] = true;
    }


    // Filter non-prime dividers
#pragma omp parallel 
    {
        int dividersSize = sqrt(max) + 1;
        bool* dividers = new bool[dividersSize];

        for (int i = 0; i < dividersSize; i++)
        {
            dividers[i] = true;
        }

        for (int i = 2; i < sqrt(dividersSize); i++)
        {
            int j = i;
            while (j + i < dividersSize)
            {
                j += i;
                dividers[j] = false;
            }
        }

        int dividersNumSize = 0;
        for (int i = 2; i < dividersSize; i++)
        {
            if (dividers[i])
            {
                dividersNumSize++;
            }
        }

        int* dividersNum = new int[dividersNumSize];
        int j = 0;
        for (int i = 2; i < dividersSize; i++)
        {
            if (dividers[i])
            {
                dividersNum[j] = i;
                j++;
            }
        }


        // Filter non-prime numbers
#pragma omp for schedule(dynamic)
        for (int i = 0; i < dividersNumSize; i++)
        {
            int num = dividersNum[i];
            int j = num * floor((min - 1) / num);
            while (j + num < max)
            {
                j += num;
                int index = j - min;
                array[index] = false;
            }
            
        }

        delete[] dividers;
    }

    // Count all prime numbers
    *size = 0;
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

    return result;
}
