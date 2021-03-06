#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

#include "src/dummy/dummy.h"

Dummy convertToLowerCase(Dummy obj)
{
    // move the obj in and move it out instead of pass by reference
    std::transform(obj.value.begin(), obj.value.end(), obj.value.begin(), [](unsigned char c){ return std::tolower(c); });
    return obj;
}

std::tuple<bool, Dummy> tupleElisonTest()
{
    Dummy test;
    // When constructing a tuple, individual obj needs to be moved
    return { true, std::move(test) };
}

int main(int argc, char const *argv[])
{
#if 0
    Dummy test1;
    std::cout << "return by value instead of pass by reference" << std::endl; 
    std::cout << "before: " << test1.value << std::endl; 
    test1 = convertToLowerCase(std::move(test1));
    std::cout << "after: " << test1.value << std::endl; 

    std::cout << "tuple return test" << std::endl; 
    auto [ yes, test2 ] = tupleElisonTest();
#endif
 
    std::vector<Dummy> testv;
    testv.reserve(10);
    std::cout << "emplace_back test 1" << std::endl; 
    testv.emplace_back(Dummy("emplace_back 1"));

    std::cout << "emplace_back test 2" << std::endl; 
    testv.emplace_back("emplace_back 2");

    std::cout << "emplace_back test 3" << std::endl; 
    testv.emplace_back(std::string("emplace_back 3"));

    std::cout << "push_back test 1" << std::endl; 
    testv.push_back(Dummy("push_back 1"));

    std::cout << "push_back test 2" << std::endl; 
    testv.push_back(std::string("push_back 2"));

    std::cout << "done" << std::endl;
    return 0;
}
