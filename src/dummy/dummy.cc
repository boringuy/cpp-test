#include "dummy.h"

#include <iostream>
#include <utility>

Dummy::Dummy() : value("Test"), key(-1) {
    std::cout << __PRETTY_FUNCTION__ << ": constructor" << std::endl;
}

Dummy::Dummy(const Dummy& other) : value(other.value), key(other.key) {
    std::cout << __PRETTY_FUNCTION__ << ": copy constructor" << std::endl;
}

Dummy::~Dummy() {
    std::cout << __PRETTY_FUNCTION__ << ": destructor" << std::endl;
}

Dummy& Dummy::operator=(const Dummy& other)
{
    std::cout << __PRETTY_FUNCTION__ << ": copy assignment" << std::endl;
    return *this = other;
}

Dummy::Dummy(Dummy&& o) noexcept :
    value(std::move(o.value)),       // explicit move of a member of class type
    key(std::exchange(o.key, 0)) // explicit move of a member of non-class type
{
    std::cout << __PRETTY_FUNCTION__ << ": move constructor" << std::endl;
}

Dummy& Dummy::operator=(Dummy&& o) noexcept
{
    std::cout << __PRETTY_FUNCTION__ << ": move assignment" << std::endl;
    value = std::move(o.value);
    key = std::exchange(o.key, 0);
    return *this;
}
