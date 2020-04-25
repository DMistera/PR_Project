#include "NaivePar.h"

std::string NaivePar::name()
{
	return "Naive Algorithm, split range array";
}

int* NaivePar::find(int min, int max, int* size)
{
	int arraySize = max - min;

	bool* array = new bool[arraySize];

	*size = 0;

#pragma omp parallel
	{
		int localSize = 0;
#pragma omp for schedule(dynamic)
		for (int i = 0; i < arraySize; i++)
		{
			if (checkPrime(min + i))
			{
				array[i] = true;
				localSize++;
			}
			else
				array[i] = false;
		}
#pragma omp atomic
		(*size) += localSize;
	}

	int* result = new int[*size];

	int j = 0;
	for (int i = 0; i < arraySize; i++)
	{
		if (array[i])
			result[j++] = min + i;
	}

	delete[] array;
	return result;
}