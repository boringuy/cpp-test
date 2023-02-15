#include <fstream>
#include <iostream>
#include <string>
#include <thread>

int main(int argc, char const *argv[])
{
    std::ifstream fs;
    fs.open("test_file.txt", std::fstream::in);
    if (!fs.is_open()) {
        std::cout << "error: cannot open file" << std::endl;
        return -1;
    }

    // does getline clear the string?
    std::string line("existing ");
    std::cout << "existing line: " << line << std::endl;
    auto &ret = std::getline(fs, line);
    if (!ret) {
        std::cout << "error: getline() failed" << std::endl;
        return -1;
    }

    std::cout << "line: " << line << std::endl;

    return 0;
}
