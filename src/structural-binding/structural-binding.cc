#include <iomanip>
#include <iostream>
#include <set>
#include <unordered_map>

int main(int argc, char** argv) {
    std::set<int> alist = {1, 2, 3};

    for (auto num : {1, 4}) {
        auto [itr, inserted] = alist.insert(num); 
        std::cout << num << " " << std::boolalpha << inserted << std::endl;
    }

    std::unordered_map<int, std::string> table = {{1, "apple"}, {2, "orange"}};

    for (auto &[key, value] : table) {
        std::cout << key << "->" << value << std::endl;
    }
}