//
// Created by Oğuz Kerem Yıldız on 24.12.2020.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Cookies/Tuple/Triplet.h"
#include <iostream>

using namespace std;

TEST_CASE("Triplet-test") {
    Triplet<int, int, int> triplet1 = Triplet(3, 4, 5);
    Triplet<int, int, int> triplet2 = Triplet(3, 4, 5);
    cout << triplet1.getA() << endl;
    bool boolean = triplet1 == triplet2;
    cout << boolean << endl;
}
