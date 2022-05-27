#include "MergeSorter.h"
#include "../speedtest/SpeedTest.h"

#include <vector>

int main() {
    int j[6] = {3, 4, 1, 5, 7, 6};
    std::vector<int> k{3, 4, 1, 5, 7, 6};
    MergeSorter<decltype(std::begin(k))> m;
    MergeSorter<decltype(std::begin(j))> n;

    SpeedTest<> st;
    st.add_test([&]() mutable {m.sort(std::begin(k), std::end(k), Method::RECURSIVE);});
    st.add_test([&]() mutable {n.sort(std::begin(j), std::end(j)-1, Method::RECURSIVE);});
    st.run_all();
    st.print_report();
    
    for(auto i: k)
        std::cout << i << ", ";
    std::cout << std::endl;
    
    for(auto l: j)
        std::cout << l << ", ";
    std::cout << std::endl;

};