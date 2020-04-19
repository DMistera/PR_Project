#pragma once

#include "PrimeFinder.h"

class Sieve :
	public PrimeFinder
{
	// Inherited via PrimeFinder
	virtual std::string name() override;
	virtual int* find(int min, int max, int* size) override;
};

