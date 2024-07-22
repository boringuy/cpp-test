#include <iostream>
#include <vector>
#include <ranges>


int main(int argc, char const *argv[])
{
    std::vector<int> testv { 1, 2, 3, 4, 5 };
    // sliding windows
    for (auto itr = testv.begin(); itr != testv.end() - 1; ++itr) {
        std::ranges::subrange subrange
        {
            std::counted_iterator{itr, 2},
            std::default_sentinel
        };
        for (auto &t : subrange) {
            std::cout << t << " ";
        }
        std::cout << std::endl;
    }
#if 0 
// c++23 only
    for (int i{}; auto t : testv | std::views::adjacent<2>) {
        auto [t0, t1] = t;
        std::cout << std::format("e = {:<{}}[{} {} {}]\n", "", 2 * i++, t0, t1);
    }
#endif
}
