#pragma once

#include <string>
#include <cstddef>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>

class PrimeFinder
{
public:
	void test(int min, int max);
protected:
	virtual std::string name() = 0;
	virtual int* find(int min, int max, int* size) = 0;
	void printResult(std::string instanceName, double seconds);
private:
	const int TESTS = 5;
	double measureTime(int min, int max);
	bool validate(int* result, int size, int* invalidNumber);
	
	bool checkPrime(int n);
};

