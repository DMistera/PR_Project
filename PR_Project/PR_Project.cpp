// PR_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

const int MAX = 100000;

int main()
{

    // Initialize array
    bool sieve[MAX];
    for (int i = 2; i < MAX; i++) {
        sieve[i] = true;
    }

    // Filter non-prime numbers
    for (int i = 2; i < sqrt(MAX); i++) {
        int j = i;
        while (j + i < MAX) {
            j += i;
            sieve[j] = false;
        }
    }

    // Print result
    for (int i = 2; i < MAX; i++) {
        if (sieve[i]) {
            std::cout << i << " ";
        }
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

