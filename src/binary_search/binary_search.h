#include <iostream>
#include <vector>

template <typename T>
int binarySearch(const std::vector<T> &data, T value) {
    int len = data.size();
    int startIndex = 0;
    int endIndex = len - 1;
    int i = 0;
    do {
        i = (endIndex - startIndex + 1) / 2 + startIndex;
//        std::cout << "s: " << startIndex << " e: " << endIndex << " i: " << i << std::endl;
        if (data[i] == value) {
//            std::cout << "found " << value << std::endl;
            return i;
        }

        if (value > data[i]) {
            startIndex = i + 1;
        } else {
            endIndex = i - 1;
        }
    } while (i > 0 && i < len && startIndex <= endIndex);

    return -1;
}

template <typename T>
int binarySearch2(const std::vector<T> &data, T value) {
    int startIndex = 0;
    int endIndex = data.size() - 1;

    int currIndex = 0;
    do {
        currIndex = (endIndex - startIndex + 1 ) / 2 + startIndex;

        if (data[currIndex] == value) {
            return currIndex;
        }

        if (data[currIndex] < value) {
            startIndex = currIndex + 1;
        } else {
            endIndex = currIndex - 1;
        }
    } while (startIndex <= endIndex);

    return -1; 
}