#include "SieveParDividers.h"

#include <time.h>

std::string SieveParDividers::name()
{
	return "Sieve Algorith, parallel finding of dividers";
}

int* SieveParDividers::find(int min, int max, int* size)
{
    int dividersSize = sqrt(max) + 1;
    int arraySize = max - min;

    // Initialize array
    bool* array = new bool[arraySize];
    bool* dividers = new bool[dividersSize];

    for (int i = 0; i < arraySize; i++) {
        array[i] = true;
    }

    int start = clock();

    // Filter non-prime dividers
    int maxI = sqrt(dividersSize);
#pragma omp parallel 
    {
#pragma omp for schedule(guided)
        for (int i = 2; i < maxI; i++) {
            int j = i;
            while (j + i < dividersSize) {
                j += i;
                dividers[j] = false;
            }
        }
    }

    int end = clock();
    std::cout << "Dividers:" << (end - start) / 1000.0f << std::endl;

    // Filter non-prime numbers
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
    delete[] dividers;

    return result;
}
