#ifndef SPEED_TEST_H
#define SPEED_TEST_H

#include <vector>
#include <functional>

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

#endif