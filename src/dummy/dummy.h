#pragma once

#include <string>

struct Dummy
{
    std::string value;
    int key;
 
    // Constructors
    Dummy();
    Dummy(std::string v);

    // Destructor
    virtual ~Dummy();

    // Copy Constructor
    Dummy(const Dummy& other);
    
    // Copy Assignment Constructor
    Dummy& operator=(const Dummy& other);

    // Move Constructor
    Dummy(Dummy&& other) noexcept;

    // Move Assignment Constructor
    Dummy& operator=(Dummy&& other) noexcept;
};
