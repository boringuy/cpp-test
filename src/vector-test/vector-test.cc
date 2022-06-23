#include <iostream>
#include <vector>

#include "src/dummy/dummy.h"

int main(int argc, char const *argv[])
{
    std::vector<std::string> testv { "1", "2", "3" };
    auto itr = testv.begin();
#if 1
    std::cout << "begin: " << *itr << std::endl;
//    std::cout << "begin - 1: " << *(--itr) << std::endl;
//    std::cout << "begin - 2: " << *(--itr) << std::endl;
//    itr = testv.end();
//    std::cout << "end: " << *(itr) << std::endl;
//    std::cout << "end + 1: " << *(++itr) << std::endl;
//    std::cout << "end + 2: " << *(++itr) << std::endl;
#endif

    // loop erase test
    std::cout << "loop erase test" << std::endl;
    itr = testv.begin();
    std::cout << "before size: " << testv.size() << std::endl;
    for ( ;itr != testv.end(); ++itr) {
        std::cout << *(itr) << std::endl;
        if (*itr == "1") {
            testv.erase(itr--);
        }
    }

    std::cout << "after size: " << testv.size() << std::endl;
    itr = testv.begin();
    for ( ;itr != testv.end(); ++itr) {
        std::cout << *(itr) << std::endl;
    }
    
    std::cout << "Erase test (move)" << std::endl;
    std::vector<Dummy> dummyv;
    std::cout << "-- Adding items 1:" << std::endl;
    dummyv.emplace_back("1");
    std::cout << "-- Adding items 2:" << std::endl;
    dummyv.emplace_back("2");
    std::cout << "-- Adding items 3:" << std::endl;
    dummyv.emplace_back("3");
    std::cout << "-- Erase item:" << std::endl;
    auto iter = dummyv.begin();
    dummyv.erase(iter);
    std::cout << "-- Fisnish Erase item:" << std::endl;

    return 0;
}
