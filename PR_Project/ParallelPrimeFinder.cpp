#include "ParallelPrimeFinder.h"

void ParallelPrimeFinder::test(int min, int max)
{
	int thread_nums[] = { MAX_THREAD_NUM , MAX_THREAD_NUM / 2, MAX_THREAD_NUM / 4 };
	for (int i = 0; i < 3; i++) {
		omp_set_num_threads(thread_nums[i]);
		try {
			std::stringstream ss;
			ss << name() << " (" << thread_nums[i] << " threads)";
			printResult(ss.str(), measureTime(min, max));
		}
		catch (std::exception e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
