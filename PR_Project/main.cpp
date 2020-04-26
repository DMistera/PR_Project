// PR_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <vector>
#include "PrimeFinder.h"
#include "Sieve.h"
#include "SieveParDividers.h"
#include "SieveParRange.h"
#include "SieveParRange2.h"
#include "SieveParEverything.h"
#include "SieveParAlternative.h"
#include "SieveParAlternative2.h"
#include "SieveParDividers2.h"
#include "Naive.h"
#include "NaivePar.h"

const int MIN = 2;
const int MAX = 100000000;

std::vector<PrimeFinder*> primeFinders = {
    //new Sieve(),
    //new SieveParRange(),
    //new SieveParRange2(),
    //new SieveParAlternative(),
    new SieveParAlternative2(),
    //new SieveParEverything(),
    //new Naive(),
    //new NaivePar()
};


void printMinMax(int min, int max)
{
    std::cout << "Instance: " << min << " - " << max << "\n";
}

void test(int min, int max)
{
    printMinMax(min, max);
    for (PrimeFinder* p : primeFinders)
    {
        p->test(min, max);
    }
}

int main()
{
    test(MIN, MAX);
    //test(MIN, MAX / 2);
    //test(MAX / 2, MIN);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

