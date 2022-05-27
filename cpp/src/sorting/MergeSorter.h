#ifndef MERGE_SORTER_H
#define MERGE_SORTER_H

#include "Sorter.h"
#include <iostream>
#include <typeinfo>


// typedef unsigned long long size_t;

template<typename RandomAccessIterator>
class MergeSorter : public Sorter<RandomAccessIterator> 
{

    public:
        MergeSorter() 
        {
            std::cout << "hello" << std::endl;
        }

        void sort(RandomAccessIterator begin, RandomAccessIterator end, 
                Method m = Method::RECURSIVE) const 
        {
            if(m == Method::RECURSIVE)
            {
                sort_recursive(begin, end);
            }
            else if(m == Method::ITERATIVE)
            {
                // sort_iterative(begin, end);
            }
            return;
        }

    private:

        void sort_recursive(RandomAccessIterator begin, RandomAccessIterator end) const
        {
            if(begin == end) return;
            auto mid = begin + ((end - begin) / 2);
            sort_recursive(begin, mid);
            sort_recursive(mid+1, end);
            sort_recursive(begin, mid, mid+1, end);
            return;
        }
        void sort_recursive(RandomAccessIterator b1, RandomAccessIterator e1, 
                          RandomAccessIterator b2, RandomAccessIterator e2) const 
        {
            if (b1 != b2)
            {
                for(auto left=b1, left_end=e1, right=b2, right_end=e2; left <= left_end && right <= right_end;) 
                {
                    for(auto right=b2; right <= right_end;)
                    {
                        if((*left) <= (*right))
                        {
                            ++right;
                        }
                        else
                        {
                            std::swap(*left, *right);
                            ++left;
                        }
                    }
                    ++left;
                }
            }
            return;
        }

        void sort_iterative(RandomAccessIterator begin, RandomAccessIterator end) const 
        {
            int split_size = 2;
            while(split_size < std::distance(begin, end))
            {
                auto split_start = begin;
                for(auto left = begin; left < end; left = split_start + split_size)
                {
                    split_size = left;
                    auto mid = left + (split_size / 2);
                    for(auto right = mid; right < split_start + split_size && right <= end;)
                    {
                        if((*left) <= (*right))
                        {
                            ++right;
                        }
                        else
                        {
                            std::swap(*left, *right);
                            ++left;
                        }
                    }
                    ++left;
                }
                split_size *= 2;
            }
        }

        // void sort_iterative(RandomAccessIterator begin, RandomAccessIterator end) const 
        // {
        //     int split = 2;
        //     int data_size = (end - start) + 1;
        //     for(int split = 2; split < data_size; split *= 2)
        //     {
        //         int split_start = start;
        //         for(int i=start; i < end; i=split_start+split)
        //         {
        //             split_start = i;
        //             int mid = (i + split) / 2;
        //             for(int j = i; j < split_start+split && j <= end;)
        //             {
        //                 if(data[i] <= data[j])
        //                 {
        //                     ++j;
        //                 }
        //                 else if(data[i] > data[j])
        //                 {
        //                     auto temp = data[i];
        //                     data[i] = data[j];
        //                     data[j] = temp;
        //                     ++i;
        //                 }
        //             }
        //         }
        //     }
        //     return data;
        // }

};

#endif