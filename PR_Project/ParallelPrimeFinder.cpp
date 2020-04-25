#include "ParallelPrimeFinder.h"

const int THREADS = 12;

void ParallelPrimeFinder::test(int min, int max)
{

	omp_set_num_threads(THREADS);
	try {
		std::stringstream ss;
		ss << name() << " (" << THREADS << " threads)";
		printResult(ss.str(), measureTime(min, max));
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
}
