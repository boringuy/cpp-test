#pragma once

#include <string>

struct Dummy
{
    std::string value;
    int key;
 
    Dummy();
    virtual ~Dummy();
    Dummy(const Dummy& other);
    Dummy& operator=(const Dummy& other);
    Dummy(Dummy&& other) noexcept;
    Dummy& operator=(Dummy&& other) noexcept;
};
