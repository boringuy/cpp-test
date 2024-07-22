#include <gtest/gtest.h>

#include "binary_search.h"

TEST(BinarySearchTest, BinarySearch) {
    std::vector<int> data { 0, 1, 5, 7, 10, 125 };

    std::cout << "testing vector size: " << data.size() << std::endl;

    EXPECT_EQ(6, data.size());

    EXPECT_EQ(1, binarySearch(data, 1));
    EXPECT_EQ(5, binarySearch(data, 125));
    EXPECT_EQ(-1, binarySearch(data, 4));
    EXPECT_EQ(-1, binarySearch(data, 300));
    EXPECT_EQ(-1, binarySearch(data, -18));
    EXPECT_EQ(0, binarySearch(data, 0));

    data = { 0, 1 };
    EXPECT_EQ(0, binarySearch(data, 0));
    EXPECT_EQ(1, binarySearch(data, 1));
    EXPECT_EQ(-1, binarySearch(data, 2));
}

TEST(BinarySearchTest, BinarySearch2) {
    std::vector<int> data { 0, 1, 5, 7, 10, 125 };

    std::cout << "testing vector size: " << data.size() << std::endl;

    EXPECT_EQ(6, data.size());

    EXPECT_EQ(1, binarySearch2(data, 1));
    EXPECT_EQ(5, binarySearch2(data, 125));
    EXPECT_EQ(-1, binarySearch2(data, 4));
    EXPECT_EQ(-1, binarySearch2(data, 300));
    EXPECT_EQ(-1, binarySearch2(data, -18));
    EXPECT_EQ(0, binarySearch2(data, 0));

    data = { 0, 1 };
    EXPECT_EQ(0, binarySearch2(data, 0));
    EXPECT_EQ(1, binarySearch2(data, 1));
    EXPECT_EQ(-1, binarySearch2(data, 2));
}
