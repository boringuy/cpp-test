#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

int main(int argc, char const *argv[])
{
    using namespace std::chrono_literals;
    using namespace std::chrono;
    auto system_now = system_clock::now().time_since_epoch();
    auto steady_now = steady_clock::now().time_since_epoch();
    auto system_now_5 = system_now - 5ms;
    std::cout << "now (from system_clock): " << duration_cast<milliseconds>(system_now).count() << " ms" << std::endl;
    std::cout << "now (from steady_clock): " << duration_cast<milliseconds>(steady_now).count() << " ms" << std::endl;

    auto start = std::chrono::steady_clock::now();
    auto converted_start = start + duration_cast<milliseconds>(system_now_5 - system_now);
//    std::cout << "converted_start (from steady_clock): " << duration_cast<milliseconds>(converted_start).count() << " ms" << std::endl;

    std::this_thread::sleep_for(1005ms);
    auto end = std::chrono::steady_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    auto converted_diff = duration_cast<milliseconds>(end - converted_start);
    std::cout << "time taken: " << diff.count() << " ms" << std::endl;
    std::cout << "time taken (converted): " << converted_diff.count() << " ms" << std::endl;
    steady_now = duration_cast< milliseconds >(steady_clock::now().time_since_epoch());
    std::cout << "now (from steady_clock): " << steady_now.count() << " ms" << std::endl;

    std::cout << "size of time_point: " << sizeof(start) << std::endl;

    time_point<system_clock> test;
    if (test == time_point<system_clock>()) {
        std::cout << "timepoint initialized to 0" << std::endl;
    }
    test = system_clock::now();
    if (test != time_point<system_clock>()) {
        std::cout << "timepoint is set" << std::endl;
    }

    // vector of timepoints
    std::vector<time_point<steady_clock> >times(10);
    std::cout << "after initialization:" << std::endl;
    for (const auto &entry : times) {
        std::cout << duration_cast<milliseconds>(entry.time_since_epoch()).count() << std::endl;
    }
    times[0] = steady_clock::now();
    std::cout << "after setting entry 0:" << std::endl;
    for (const auto &entry : times) {
        std::cout << duration_cast<milliseconds>(entry.time_since_epoch()).count() << std::endl;
    }
    return 0;
}
