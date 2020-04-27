#pragma once
#include "ParallelPrimeFinder.h"
class SieveParRangeFinal :
	public ParallelPrimeFinder
{
	// Inherited via ParallelPrimeFinder
	virtual std::string name() override;
	virtual int* find(int min, int max, int* size) override;
};

