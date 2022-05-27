#include "Sorter.h"


template<typename T>
class Quicksort : public Sorter<T> 
{
    public:
        T& sort(T& data, size_t start, size_t end)
        {
            // Randomize

            // Start Sorting

            // Select Pivot and get sorted index
            T& pivot = end;

            // Call Paritition

            // Repeat
        }

        T& partition(T& data, size_t start, size_t end)
        {
            T& pivot = data[end];

            // while(i < pivot && j < end)
            // {
            //     while(data[i] < pivot && i < pivot)
            //     {
            //         ++i;
            //     }
            //     while(data[j] > pivot && j < end)
            //     {
            //         ++j;
            //     }
                
            // }
            while(i < j && j < end)
            {
                if(data[i] < pivot && data[j] > pivot)
                {
                    ++i; ++j;
                }
                else if(data[i] > pivot && data[j] > pivot)
                {
                    ++j;
                }
                else if(data[i] < pivot && data[j] < pivot)
                {
                    ++i;
                }
                else 
                {
                    std::swap(&data[i], &data[j])
                    ++i;
                    ++j;
                }
            }
        }

};