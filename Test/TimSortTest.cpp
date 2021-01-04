//
// Created by Oğuz Kerem Yıldız on 4.01.2021.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Cookies/Sort/TimSort.h"
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

TEST_CASE("TimSort-test") {
    vector<int> v = vector<int>();
    v.push_back(7);
    v.push_back(15);
    v.push_back(3);
    v.push_back(77);
    v.push_back(8);
    v.push_back(100);
    v.push_back(19);
    v.push_back(1);
    v.push_back(88);
    v.push_back(22);
    int *array = new int[9];
    array[0] = 7;
    array[1] = 15;
    array[2] = 3;
    array[3] = 77;
    array[4] = 8;
    array[5] = 19;
    array[6] = 1;
    array[7] = 88;
    array[8] = 22;
    Comparator<int> *comparator = new IntegerComparator();
    auto timSort = TimSort<int>(comparator);
    timSort.sort(v, v.size());
    timSort.sort(array, 9);
    for (int i : v) {
        cout << i << endl;
    }
    cout << "" << endl;
    for (int i = 0; i < 9; ++i) {
        cout << array[i] << endl;
    }
}