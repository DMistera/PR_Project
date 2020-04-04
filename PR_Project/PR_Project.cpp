// PR_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>

const int MIN = 99999000;
const int MAX = 100000000;

int main()
{
    // Start timer
    clock_t start = clock();

    int dividersSize = sqrt(MAX) + 1;
    int arraySize = MAX - MIN;

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
        int j = i * floor((MIN - 1) / i);
        while (j + i < MAX) {
            j += i;
            int index = j - MIN;
            if (index < 0 || index >= arraySize) {
                std::cout << index;
            }
            array[index] = false;
        }
    }

    // End timer
    clock_t end = clock();

     //Print result
    for (int i = 0; i < arraySize; i++) {
        if (array[i]) {
            std::cout << i + MIN << " ";
        }
    }

    std::cout << std::endl;
    std::cout << "Numbers found in " << (end - start)/1000.0 << " seconds\n";

    delete[] array;
    delete[] dividers;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

