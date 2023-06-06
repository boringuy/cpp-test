#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <stdio.h>
#include <string.h>

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

struct DummyHolder {
    DummyHolder(std::unique_ptr<Dummy> pointer):
        m_pointer(std::move(pointer))
    {
    }

    void print() {
        std::cout << "print: " << m_pointer->value << std::endl;
    }
    std::unique_ptr<Dummy> m_pointer;

};

Dummy UniversalReferenceTest(Dummy &&dummy) 
{
    Dummy test(std::move(dummy)); 

    return test;
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

    DummyHolder holder(std::make_unique<Dummy>("unique_ptr move into constructor test"));
    holder.print();

    Dummy test1("test1");
    // failed to compile without std::move
    // auto test2 = UniversalReferenceTest(test1); 
    auto test2 = UniversalReferenceTest(std::move(test1));
    std::cout << "test1: " << test1.value << std::endl;
    std::cout << "test2: " << test2.value << std::endl;

    // moving shared ptr
    auto dummyPtr = std::make_shared<Dummy>("testshared1");
    auto dummerPtr = dummyPtr;
    auto dummererPtr = std::move(dummerPtr);

    if (dummyPtr) {
    	std::cout << "dummyPtr ok: ref count: " << dummyPtr.use_count() << std::endl;
    } else {
    	std::cout << "dummyPtr null" << std::endl;
    }
    if (dummerPtr) {
    	std::cout << "dummerPtr ok: ref count: " << dummerPtr.use_count() << std::endl;
    } else {
    	std::cout << "dummerPtr null" << std::endl;
    }
    if (dummererPtr) {
    	std::cout << "dummererPtr ok: ref count: " << dummererPtr.use_count() << std::endl;
    } else {
    	std::cout << "dummererPtr null" << std::endl;
    }
    return 0;
}
