#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

struct Dummy
{
    std::string s;
    int k;
 
    Dummy() : s("Test"), k(-1) {
        std::cout << __PRETTY_FUNCTION__ << ": constructor" << std::endl;
    }

    Dummy(const Dummy& o) : s(o.s), k(o.k) {
        std::cout << __PRETTY_FUNCTION__ << ": copy constructor" << std::endl;
    }

    Dummy& operator=(const Dummy& other)
    {
        std::cout << __PRETTY_FUNCTION__ << ": copy assignment" << std::endl;
        return *this = other;
    }

    Dummy(Dummy&& o) noexcept :
        s(std::move(o.s)),       // explicit move of a member of class type
        k(std::exchange(o.k, 0)) // explicit move of a member of non-class type
    {
        std::cout << __PRETTY_FUNCTION__ << ": move constructor" << std::endl;
    }

    Dummy& operator=(Dummy&& o) noexcept
    {
        std::cout << __PRETTY_FUNCTION__ << ": move assignment" << std::endl;
        s = std::move(o.s);
        k = std::exchange(o.k, 0);
        return *this;
    }
};

Dummy convertToLowerCase(Dummy obj)
{
    // move the obj in and move it out instead of pass by reference
    std::transform(obj.s.begin(), obj.s.end(), obj.s.begin(), [](unsigned char c){ return std::tolower(c); });
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
    Dummy test1;
    std::cout << "return by value instead of pass by reference" << std::endl; 
    std::cout << "before: " << test1.s << std::endl; 
    test1 = convertToLowerCase(std::move(test1));
    std::cout << "after: " << test1.s << std::endl; 

    std::cout << "tuple return test" << std::endl; 
    auto [ yes, test2 ] = tupleElisonTest();

    return 0;
}
