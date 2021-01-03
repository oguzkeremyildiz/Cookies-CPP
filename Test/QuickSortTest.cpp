//
// Created by Oğuz Kerem Yıldız on 3.01.2021.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Cookies/Sort/QuickSort.h"
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

TEST_CASE("QuickSort-test") {
    vector<int> v = vector<int>();
    v.push_back(15);
    v.push_back(3);
    v.push_back(8);
    v.push_back(19);
    v.push_back(1);
    v.push_back(88);
    v.push_back(22);
    Comparator<int> *comparator = new IntegerComparator();
    auto quickSort = QuickSort<int>(comparator);
    v = quickSort.sort(v, 0, v.size() - 1);
    for (int i : v) {
        cout << i << endl;
    }
}