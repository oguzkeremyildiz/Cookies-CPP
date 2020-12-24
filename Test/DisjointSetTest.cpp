//
// Created by Oğuz Kerem Yıldız on 24.12.2020.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Cookies/Set/DisjointSet.h"
#include <vector>

using namespace std;

TEST_CASE("DisjointSet-test") {
    int vector1[4];
    vector1[0] = 1;
    vector1[1] = 3;
    vector1[2] = 5;
    vector1[3] = 7;
    DisjointSet<int> set = DisjointSet(vector1, 4);
    cout << set.findSetWithIndex(1) << endl;
    cout << set.findSetWithIndex(2) << endl;
    set.unionWithType(3, 5);
    cout << set.findSetWithIndex(1) << endl;
    cout << set.findSetWithIndex(2) << endl;
}