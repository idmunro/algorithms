#ifndef MERGE_SORTER_H
#define MERGE_SORTER_H

#include "Sorter.h"
#include <iostream>


template<typename T>
class MergeSorter : public Sorter<T> {

    public:
        MergeSorter() {
            std::cout << "hello";
        }
        T& sort(T &data) const {
            return data;
        }

};

#endif