#include "PrimeFinder.h"

void PrimeFinder::test(int min, int max)
{
	try {
		printResult(name(), measureTime(min, max));
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
}

void PrimeFinder::printResult(std::string instanceName, double seconds)
{
	std::cout << instanceName << " found all primes in " << seconds;
}

double PrimeFinder::measureTime(int min, int max)
{
	int size;
	clock_t start = clock();
	int* result = find(min, max, &size);
	clock_t end = clock();
	int invalidNumber;
	if (!validate(result, size, &invalidNumber)) {
		std::stringstream ss;
		ss << name() << " failed validation: " << invalidNumber << " is not a prime number.";
		throw std::exception(ss.str().c_str());
	}
	double elapsed = (end - start) / 1000.0;
	return elapsed;
}

bool PrimeFinder::validate(int* result, int size, int* invalidNumber)
{
	srand(time(NULL));
	for (int i = 0; i < TESTS; i++) {
		int index = rand() % size;
		if (!checkPrime(result[index])) {
			*invalidNumber = result[index];
			return false;
		}
	}
	return true;
}

bool PrimeFinder::checkPrime(int n)
{
	for (int i = 2; i < sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
