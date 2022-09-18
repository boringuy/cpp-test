#include <iostream>

template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename func>
void lambdaTemplate(func &&callback) {
    callback(1);
}

template <typename T, typename func>
void lambdaTemplateAndRegularTemplate(func &&callback) {
    T x = 3;
    callback(x);
}

int main(int argc, char const *argv[])
{
    int a = 1;
    int b = 2;
    // add can be cause without specifying the template type
    std::cout << "add: " << add(a, b) << std::endl;
    std::cout << "add: " << add(1, 2) << std::endl;

    // using template to accept lambda function
    lambdaTemplate([](int x) { std::cout << "got: " << x << std::endl; });

    // the lambda can still be deduced automatically when mixing with regulatr template
    lambdaTemplateAndRegularTemplate<int>([](int x) { std::cout << "got: " << x << std::endl; });
    return 0;
}
