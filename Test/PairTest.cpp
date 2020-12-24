//
// Created by Oğuz Kerem Yıldız on 23.12.2020.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Cookies/Tuple/Pair.h"
#include <iostream>

using namespace std;

TEST_CASE("Pair-test") {
    Pair<int, int> pair2 = Pair(5, 3);
    Pair<int, int> pair1 = Pair(7, 3);
    cout << pair1.getKey() << endl;
    cout << pair1.getValue() << endl;
    bool  boolean = pair1 == pair2;
    cout << boolean << endl;
    cout << pair2.toString() << endl;
}