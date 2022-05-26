#include "MergeSorter.h"
#include <vector>
#include <typeinfo>
#include <functional>
#include <string>

template<typename Functor = std::function<void()>>
struct SpeedTest 
{
    std::vector<Functor> funcs;
    std::vector<double> runtimes;

    void add_test(Functor func) 
    {
        funcs.push_back(func);
    }

    void run_all() 
    {
        for(auto &f: funcs) 
        {
            time_t start, end;
            time(&start);

            f();

            time(&end);
            double elapsed = double(end - start);

            runtimes.push_back(elapsed);
        }
    }

    void print_report() 
    {
        int count = 0;
        for(double d: runtimes)
        {
            std::printf("Function %d Runtime: %.04f seconds\n", ++count, d);
        }
    }


};

int main() {
    int j[6] = {3, 4, 1, 5, 7, 6};
    std::vector<int> k{3, 4, 1, 5, 7, 6};
    MergeSorter<std::vector<int>> m;
    MergeSorter<int[6]> n;

    SpeedTest<> st;
    st.add_test([&]() mutable {m.sort(k, 0, 5, Method::ITERATIVE);});
    st.add_test([&]() mutable {n.sort(j, 0, 5, Method::ITERATIVE);});
    st.run_all();
    st.print_report();
    
    for(auto i: k)
        std::cout << i << ", ";
    std::cout << std::endl;
    
    for(auto i: j)
        std::cout << i << ", ";
    std::cout << std::endl;

};