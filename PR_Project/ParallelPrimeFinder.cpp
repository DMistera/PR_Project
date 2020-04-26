#include "ParallelPrimeFinder.h"

void ParallelPrimeFinder::test(int min, int max)
{

	omp_set_num_threads(MAX_THREAD_NUM);
	try {
		std::stringstream ss;
		ss << name() << " (" << MAX_THREAD_NUM << " threads)";
		printResult(ss.str(), measureTime(min, max));
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
}
