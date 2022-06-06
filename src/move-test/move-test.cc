#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

struct A
{
    std::string s;
    int k;
 
    A() : s("Test"), k(-1) {
        std::cout << __PRETTY_FUNCTION__ << ": constructor" << std::endl;
    }

    A(const A& o) : s(o.s), k(o.k) {
        std::cout << __PRETTY_FUNCTION__ << ": copy constructor" << std::endl;
    }

    A& operator=(const A& other)
    {
        std::cout << __PRETTY_FUNCTION__ << ": copy assignment" << std::endl;
        return *this = other;
    }

    A(A&& o) noexcept :
        s(std::move(o.s)),       // explicit move of a member of class type
        k(std::exchange(o.k, 0)) // explicit move of a member of non-class type
    {
        std::cout << __PRETTY_FUNCTION__ << ": move constructor" << std::endl;
    }

    A& operator=(A&& o) noexcept
    {
        std::cout << __PRETTY_FUNCTION__ << ": move assignment" << std::endl;
        s = std::move(o.s);
        k = std::exchange(o.k, 0);
        return *this;
    }
};

A convertToLowerCase(A obj)
{
    // move the obj in and move it out instead of pass by reference
    std::transform(obj.s.begin(), obj.s.end(), obj.s.begin(), [](unsigned char c){ return std::tolower(c); });
    return obj;
}

std::tuple<bool, A> tupleElisonTest()
{
    A test;
    // When constructing a tuple, individual obj needs to be moved
    return { true, std::move(test) };
}

int main(int argc, char const *argv[])
{
    A test1;
    std::cout << "return by value instead of pass by reference" << std::endl; 
    std::cout << "before: " << test1.s << std::endl; 
    test1 = convertToLowerCase(std::move(test1));
    std::cout << "after: " << test1.s << std::endl; 

    std::cout << "tuple return test" << std::endl; 
    auto [ yes, test2 ] = tupleElisonTest();

    return 0;
}
