#include "MergeSorter.h"
#include "../speedtest/SpeedTest.h"

#include <vector>

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