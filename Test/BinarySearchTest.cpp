//
// Created by Oğuz Kerem Yıldız on 4.01.2021.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Cookies/Search/BinarySearch.h"
#include <iostream>

using namespace std;

class IntegerComparator : public Comparator<int> {
public:
    IntegerComparator() = default;
    virtual int compare(int first, int second) {
        if (first > second) {
            return 1;
        } else if (first < second) {
            return -1;
        } else {
            return 0;
        }
    }
};

TEST_CASE("BinarySearchTest-test") {
    vector<int> v = vector<int>();
    v.push_back(1);
    v.push_back(3);
    v.push_back(7);
    v.push_back(8);
    v.push_back(15);
    v.push_back(19);
    v.push_back(22);
    v.push_back(77);
    v.push_back(88);
    v.push_back(100);
    Comparator<int> *comparator = new IntegerComparator();
    auto binarySearch = BinarySearch<int>(comparator);
    cout << binarySearch.search(v, 0, v.size() - 1, 100) << endl;
    int *array = new int[9];
    array[0] = 3;
    array[1] = 7;
    array[2] = 15;
    array[3] = 17;
    array[4] = 22;
    array[5] = 23;
    array[6] = 47;
    array[7] = 54;
    array[8] = 67;
    cout << binarySearch.search(array, 0, 8, 23) << endl;
}