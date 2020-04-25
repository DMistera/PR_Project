#pragma once

#include "ParallelPrimeFinder.h"

class NaivePar :
	public ParallelPrimeFinder
{
	// Inherited via ParallelPrimeFinder
	virtual std::string name() override;
	virtual int* find(int min, int max, int* size) override;
};