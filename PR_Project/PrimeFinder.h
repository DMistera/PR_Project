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
	virtual void test(int min, int max);
protected:
	virtual std::string name() = 0;
	virtual int* find(int min, int max, int* size) = 0;
	void printResult(std::string instanceName, double seconds);
	double measureTime(int min, int max);
private:
	const int TESTS = 5;
	void validate(int min, int max, int* result, int size);
	bool checkPrime(int n);
};

