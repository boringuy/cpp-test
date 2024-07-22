#include <algorithm>
#include <iostream>
#include <vector>
#include <ranges>


int main(int argc, char const *argv[])
{
    std::vector<int> testv { 1, 2, 4, 5 };
    std::cout << "[ ";
    std::copy(testv.begin(), testv.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << " ]" << std::endl;

    std::cout << "Searching 0" << std::endl;
    auto itr = std::lower_bound(testv.begin(), testv.end(), 0);
    std::cout << "lower_bound: " << *itr << std::endl;
    itr = std::upper_bound(testv.begin(), testv.end(), 0);
    std::cout << "upper_bound: " << *itr << std::endl;
    if (itr == testv.begin()) {
        std::cout << "itr is begin()" << std::endl;
    }

    std::cout << "Searching 6" << std::endl;
    itr = std::lower_bound(testv.begin(), testv.end(), 6);
    std::cout << "lower_bound: " << *itr << std::endl;
    itr = std::upper_bound(testv.begin(), testv.end(), 6);
    std::cout << "upper_bound: " << *itr << std::endl;

    if (itr == testv.end()) {
        std::cout << "itr is end()" << std::endl;
    }

    auto compare = [](int x, int y){ return x < y; };
    std::cout << "Searching 3 (not exists)" << std::endl;
    itr = std::lower_bound(testv.begin(), testv.end(), 3, compare);
    std::cout << "lower_bound: " << *itr << std::endl;
    itr = std::upper_bound(testv.begin(), testv.end(), 3, compare);
    std::cout << "upper_bound: " << *itr << std::endl;

    std::cout << "Searching 4 (exists)" << std::endl;
    itr = std::lower_bound(testv.begin(), testv.end(), 4);
    std::cout << "lower_bound: " << *itr << std::endl;
    itr = std::upper_bound(testv.begin(), testv.end(), 4);
    std::cout << "upper_bound: " << *itr << std::endl;


    std::cout << "Erase test: " << std::endl;
    auto startItr = std::lower_bound(testv.begin(), testv.end(), 2);
    std::cout << "start: " << *startItr << std::endl;
    auto endItr = std::lower_bound(testv.begin(), testv.end(), 4);
    std::cout << "end before erase: " << *endItr << std::endl;
    testv.erase(startItr, endItr);
    std::cout << "end after erase: " << *endItr << std::endl;

    std::cout << "[ ";
    std::copy(testv.begin(), testv.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << " ]" << std::endl;

}
