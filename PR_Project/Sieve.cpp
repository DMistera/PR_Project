#include "Sieve.h"

std::string Sieve::name()
{
    return "Sieve Algorithm";
}

int* Sieve::find(int min, int max, int* size)
{
    int dividersSize = sqrt(max) + 1;
    int arraySize = max - min;

    // Initialize array
    bool* array = new bool[arraySize];
    bool* dividers = new bool[dividersSize];

    std::cout << "Initialized arrays";

    // Filter non-prime dividers
    for (int i = 2; i < sqrt(dividersSize); i++) {
        int j = i;
        while (j + i < dividersSize) {
            j += i;
            dividers[j] = false;
        }
    }

    std::cout << "Filtered dividers";

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

    std::cout << "Filtered non-primes";

    // Count all prime numbers
    *size = 0;
    for (int i = 0; i < arraySize; i++) {
        if (array[i]) {
            (*size)++;
        }
    }

    std::cout << "Counted primes";

    // Insert all prime numbers into an array
    int* result = new int[*size];
    int j = 0;
    for (int i = 0; i < arraySize; i++) {
        if (array[i]) {
            result[j++] = min + i;
        }
    }

    std::cout << "Inserted primes";

    // Clean up
    delete[] array;
    delete[] dividers;

    return result;

}