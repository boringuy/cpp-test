#include <iostream>
#include <string>
#include <variant>

int main(int argc, char const *argv[])
{
    std::variant<int, std::string> v;
    std::cout << std::boolalpha
              << "variant holds int? "
              << std::holds_alternative<int>(v) << '\n'
              << "variant holds string? "
              << std::holds_alternative<std::string>(v) << '\n';

    std::variant<std::string, int> v2;
    std::cout << std::boolalpha
              << "variant holds int? "
              << std::holds_alternative<int>(v2) << '\n'
              << "variant holds string? "
              << std::holds_alternative<std::string>(v2) << '\n';
}
