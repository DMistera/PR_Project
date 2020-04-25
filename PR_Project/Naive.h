#pragma once

#include "PrimeFinder.h"

class Naive :
	public PrimeFinder
{
	virtual std::string name() override;
	virtual int* find(int min, int max, int* size) override;
};