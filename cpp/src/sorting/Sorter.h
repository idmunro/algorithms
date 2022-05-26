#ifndef SORTER_H
#define SORTER_H

#include <array>

typedef unsigned long long size_t;

enum class Method {
    RECURSIVE,
    ITERATIVE
};

template<typename T> 
class Sorter {
    
    public:

    // .sort() Return the original data structure in sorted order
        T& sort(T &data, size_t start, size_t end, const Method m) const;

    // .sort_copy() Return a new data structure of copied valus in sorted order
        // virtual T& sort_copy(const T& data) const;

    // .sort_iter() Return an iterator of sorted values
        // virtual auto sort_iter(const T& data) const -> decltype(std::begin(data));

    // .sort_indices() Return indices in proper sorted order
        // virtual T& sort_indices(const T& data) const;
    protected:
        Sorter() = default;
        
};

#endif