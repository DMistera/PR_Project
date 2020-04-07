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

    for (int i = 0; i < arraySize; i++) {
        array[i] = true;
    }

    // Filter non-prime dividers
    for (int i = 2; i < sqrt(dividersSize); i++) {
        int j = i;
        while (j + i < dividersSize) {
            j += i;
            dividers[j] = false;
        }
    }

    // Filter non-prime numbers
    for (int i = 2; i < dividersSize; i++) {
        int j = i * floor((min - 1) / i);
        while (j + i < max) {
            j += i;
            int index = j - min;
            if (index < 0 || index >= arraySize) {
                std::cout << index;
            }
            array[index] = false;
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
