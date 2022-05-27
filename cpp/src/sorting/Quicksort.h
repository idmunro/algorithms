#include "Sorter.h"


template<typename T>
class Quicksort : public Sorter<T> 
{
    public:
        T& sort(T& data, size_t start, size_t end)
        {
            // Randomize

            // Start Sorting

            // Select Pivot
            T& pivot = end;

            // Call Paritition

            // Repeat
        }

        T& partition(T& data, size_t start, size_t end, size_t pivot_index)
        {
            T& pivot = data[pivot_index];

            while(i < pivot && j < end)
            {
                while(data[i] < pivot)
                {
                    
                }
            }
            for(int i=start; i<pivot_index;)
            {
                for(int j=pivot_index+1; j<end;)
                {
                    if(data[i] < pivot && data[j] > pivot)
                    {
                        ++i; ++j;
                    }
                    else if(data[i] > pivot && data[j] > pivot)
                    {
                        
                    }
                    else if(data[i] > pivot && data[j] < pivot)
                    {

                    }
                    else 
                    {
                        ++i;
                        ++j;
                    }

                }
            }
        }

};