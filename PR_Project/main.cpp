// PR_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <vector>
#include "PrimeFinder.h"
#include "Sieve.h"

const int MIN = 90000000;
const int MAX = 100000000;

std::vector<PrimeFinder*> primeFinders = {
    new Sieve()
};

int main()
{
    for (PrimeFinder* p : primeFinders) {
        p->test(MIN, MAX);
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

