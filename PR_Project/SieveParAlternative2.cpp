#include "SieveParAlternative2.h"

std::string SieveParAlternative2::name()
{
	return "Sieve Algorith, split range array, separate dividers";
}

int* SieveParAlternative2::find(int min, int max, int* size)
{
    int dividersSize = sqrt(max) + 1;
    int arraySize = max - min;

    // Initialize array
    bool* array = new bool[arraySize];

    *size = 0;

    for (int i = 0; i < arraySize; i++)
    {
        array[i] = true;
    }

#pragma omp parallel
    {

        bool* dividers = new bool[dividersSize];

        for (int i = 0; i < dividersSize; i++)
        {
            dividers[i] = true;
        }

        // Filter non-prime dividers
        for (int i = 2; i < sqrt(dividersSize); i++)
        {
            int j = i;
            while (j + i < dividersSize)
            {
                j += i;
                dividers[j] = false;
            }
        }

        // Filter non-prime numbers
        int maxT = omp_get_num_threads();
        int t = omp_get_thread_num();
        int minIndex = min + t * arraySize / maxT;
        int maxIndex = min + (t + 1) * arraySize / maxT;
        for (int i = 2; i < dividersSize; i++)
        {
            if (dividers[i])
            {
                int j = i * floor((minIndex - 1) / i);
                if (j < i)
                {
                    j += i;
                }
                while (j + i < maxIndex)
                {
                    j += i;
                    int index = j - min;
                    array[index] = false;
                }
            }
        }

        delete[] dividers;
    }

    for (int i = 0; i < arraySize; i++)
    {
        if (array[i])
        {
            (*size)++;
        }
    }

    // Insert all prime numbers into an array
    int* result = new int[*size];
    int j = 0;
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i])
        {
            result[j++] = min + i;
        }
    }


    // Clean up
    delete[] array;

    return result;
}
