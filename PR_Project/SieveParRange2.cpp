#include "SieveParRange2.h"

std::string SieveParRange2::name()
{
	return "Sieve Algorith, parallel finding of primes in given range 2";
}

int* SieveParRange2::find(int min, int max, int* size)
{
    int dividersSize = sqrt(max) + 1;
    int arraySize = max - min;

    // Initialize array
    bool* array = new bool[arraySize];
    bool* dividers = new bool[dividersSize];

    for (int i = 0; i < dividersSize; i++)
    {
        dividers[i] = true;
    }

    for (int i = 0; i < arraySize; i++)
    {
        array[i] = true;
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

    int dividersNumSize = 0;
    for (int i = 2; i < dividersSize; i++)
    {
        if (dividers[i])
        {
            dividersNumSize++;
        }
    }

    int* dividersNum = new int[dividersNumSize];
    
    int k = 0;
    for (int i = 2; i < dividersSize; i++)
    {
        if (dividers[i])
        {
            dividersNum[k++] = i;
        }
    }
    

    double start = clock();
    // Filter non-prime numbers
#pragma omp parallel
    {
#pragma omp for schedule(dynamic)
        for (int i = 0; i < dividersNumSize; i++)
        {
            int num = dividersNum[i];
            int j = num * ((min - 1) / num);
            if (j < num)
            {
                j += num;
            }
            while (j + num < max)
            {
                j += num;
                int index = j - min;
                if (array[index])
                {
                    array[index] = false;
                }
            }

        }
    }


    double end = clock();
    std::cout << (end - start) / 1000.0 << std::endl;

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
    delete[] dividers;

    return result;
}
