#include <iostream>

int main(int argc, char const *argv[])
{
    double v3 = -74.073300;        // Can be represented exactly.
    float v4 = (float) v3;

    double v5 = 4.635700;        // Cannot be represented exactly.
    float v6 = (float) v5;

    std::cout << "v3 = " << v3 << std::endl;
    std::cout << "v4 = " << v4 << std::endl;
    std::cout << "v5 = " << v5 << std::endl;
    std::cout << "v6 = " << v6 << std::endl;
    return 0;
}
