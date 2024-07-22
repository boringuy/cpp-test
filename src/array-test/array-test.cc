#include <iostream>
#include <algorithm>
#include <array>


template<typename T>
void printArray(const T&a) {
    std::cout << "[ ";
    for (auto value : a ) {
        std::cout << value << " ";
    }
    std::cout << "]" << std::endl;
}

template<typename T>
void print2DArray(const T&a) {
    for (auto &array : a ) {
        std::cout << "[ ";
        for (auto &value : array ) {
            std::cout << value << " ";
        }
        std::cout << "]" << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    std::array<std::string, 3> testarray { "1", "2", "3" };

    constexpr int x = 3;
    constexpr int y = 4;
    std::array<int, x> testx { -1 }; 
    testx.fill(-1);
    printArray(testx);
    std::fill(testx.begin(), testx.end(), 0);
    printArray(testx);

    std::array<std::array<int, x>, y> testxy { -1 }; 
    testxy.fill({-1, -1, -1});
    print2DArray(testxy);
}
