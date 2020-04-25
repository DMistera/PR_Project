#pragma once

#include "PrimeFinder.h"
#include "omp.h"

class ParallelPrimeFinder :
	public PrimeFinder
{
public:
	void test(int min, int max);
private:
	const int MAX_THREAD_NUM = 12;
};

