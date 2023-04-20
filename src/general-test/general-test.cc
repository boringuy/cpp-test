#include <iostream>
#include <string>
#include <variant>

int main(int argc, char const *argv[])
{
    bool a = false, b = true;

    if (a = true, b = false) {
        std::cout << "(a = true, b) = true" << std::endl;
    } else {
        std::cout << "(a = true, b) = false" << std::endl;
    }
    std::cout << std::boolalpha << "a = " << a << ", b = " << b << std::endl;

    a = false, b = true;
    if (b = false, a = true) {
        std::cout << "(b, a = true) = true" << std::endl;
    } else {
        std::cout << "(b, a = true) = false" << std::endl;
    }
    std::cout << std::boolalpha << "a = " << a << ", b = " << b << std::endl;

    a = false, b = true;
    if (a = true; b = false) {
        std::cout << "(a = true; b) = true" << std::endl;
    } else {
        std::cout << "(a = true; b) = false" << std::endl;
    }
    std::cout << std::boolalpha << "a = " << a << ", b = " << b << std::endl;

    a = false, b = true;

    if (b = false; a = true) {
        std::cout << "(b; a = true) = true" << std::endl;
    } else {
        std::cout << "(b; a = true) = false" << std::endl;
    }
    std::cout << std::boolalpha << "a = " << a << ", b = " << b << std::endl;
}
