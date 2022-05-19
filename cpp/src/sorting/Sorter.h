

class Sorter {

// Public

    public:
        Sorter() = default;
        ~Sorter() = default;

    // .sort() Return the original data structure in sorted order
        template<typename T>
        void sort(T (&data)[]) const;

        template<typename T>
        void sort(T &data) const;

    // .sort_copy() Return a new data structure of copied valus in sorted order
        template<typename T>
        T* sort_copy(const T(&data)[]) const;

        template<typename T>
        T* sort_copy(const T& data) const;

    // .sort_iter() Return an iterator of sorted values
        // template<typename T>
        // T* sort_iter(const T(&data)[]) const;

        // template<typename T>
        // T* sort_iter(const T& data) const;

    // .sort_indices() Return indices in proper sorted order
        template<typename T>
        T* sort_indices(const T(&data)[]) const;

        template<typename T>
        T* sort_indices(const T& data) const;
        
// Protected

    // .store_order()

    // .apply_order()

};