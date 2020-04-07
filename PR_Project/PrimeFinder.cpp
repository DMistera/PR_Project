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
	std::cout << instanceName << " found all primes in " << seconds << std::endl;
}

double PrimeFinder::measureTime(int min, int max)
{
	int size;
	clock_t start = clock();
	int* result = find(min, max, &size);
	clock_t end = clock();
	validate(min, max, result, size);
	double elapsed = (end - start) / 1000.0;
	delete result;
	return elapsed;
}

void PrimeFinder::validate(int min, int max, int* result, int size)
{
	std::stringstream ss;
	ss << name() << " failed validation: ";
	srand(time(NULL));
	for (int i = 0; i < TESTS; i++) {
		int index = rand() % size;
		int n = result[index];
		if (n < min) {
			ss << n << " is lesser than minimum";
			throw std::exception(ss.str().c_str());
		}
		if (n > max) {
			ss << n << " is higher than maximum.";
			throw std::exception(ss.str().c_str());
		}
		if (!checkPrime(n)) {
			ss << n << " is not a prime number.";
			throw std::exception(ss.str().c_str());
		}
	}
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
