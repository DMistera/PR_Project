#include "SieveParDividers.h"

#include <time.h>

std::string SieveParDividers::name()
{
	return "Sieve Algorith, parallel finding of primes in given range, separated dividers";
}

int* SieveParDividers::find(int min, int max, int* size)
{
    int arraySize = max - min;

    // Initialize array
    bool* array = new bool[arraySize];

    for (int i = 0; i < arraySize; i++) {
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

        for (int i = 2; i < sqrt(dividersSize); i++) {
            int j = i;
            while (j + i < dividersSize) {
                j += i;
                dividers[j] = false;
            }
        }


        // Filter non-prime numbers
        #pragma omp for schedule(dynamic, 1000)
        for (int i = 2; i < dividersSize; i++) {
            if (dividers[i]) {
                int j = i * floor((min - 1) / i);
                while (j + i < max) {
                    j += i;
                    int index = j - min;
                    array[index] = false;
                }
            }
        }

        delete[] dividers;
    }

    // Count all prime numbers
    *size = 0;
    for (int i = 0; i < arraySize; i++) {
        if (array[i]) {
            (*size)++;
        }
    }

    // Insert all prime numbers into an array
    int* result = new int[*size];
    int j = 0;
    for (int i = 0; i < arraySize; i++) {
        if (array[i]) {
            result[j++] = min + i;
        }
    }

    // Clean up
    delete[] array;

    return result;
}
