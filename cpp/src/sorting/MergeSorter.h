#ifndef MERGE_SORTER_H
#define MERGE_SORTER_H

#include "Sorter.h"
#include <iostream>
#include <typeinfo>


// typedef unsigned long long size_t;

template<typename T>
class MergeSorter : public Sorter<T> 
{

    public:
        MergeSorter() 
        {
            std::cout << "hello" << std::endl;
        }

        T& sort(T &data, size_t start, size_t end, Method m = Method::RECURSIVE) const 
        {
            if(m == Method::RECURSIVE)
            {
                sort_recursive(data, start, end);
            }
            else if(m == Method::ITERATIVE)
            {
                sort_iterative(data, start, end);
            }
            return data;
        }

    private:

        T& sort_recursive(T &data, size_t start, size_t end) const
        {
            if(start == end) return data;
            size_t mid = start + ((end - start) / 2);
            sort_recursive(data, start, mid);
            sort_recursive(data, mid+1, end);
            sort_recursive(data, start, mid, mid+1, end);
            return data;
        }
        T& sort_recursive(T &data, size_t s1, size_t e1, size_t s2, size_t e2) const 
        {
            if (s1 == s2) 
            {
                return data;
            }
            else
            {
                for(int i=s1; i<=e1;) 
                {
                    for(int j=s2; j<=e2 && i<=e1;)
                    {
                        if(data[i] <= data[j])
                        {
                            ++j;
                        }
                        else if(data[i] > data[j])
                        {
                            auto temp = data[i];
                            data[i] = data[j];
                            data[j] = temp;
                            ++i;
                        }
                    }
                    ++i;
                }
            }
            return data;
        }

        T& sort_iterative(T &data, size_t start, size_t end) const 
        {
            int split = 2;
            int data_size = (end - start) + 1;
            for(int split = 2; split < data_size; split *= 2)
            {
                int split_start = start;
                for(int i=start; i < end; i=split_start+split)
                {
                    split_start = i;
                    int mid = (i + split) / 2;
                    for(int j = i; j < split_start+split && j <= end;)
                    {
                        if(data[i] <= data[j])
                        {
                            ++j;
                        }
                        else if(data[i] > data[j])
                        {
                            auto temp = data[i];
                            data[i] = data[j];
                            data[j] = temp;
                            ++i;
                        }
                    }
                }
            }
            return data;
        }

};

#endif