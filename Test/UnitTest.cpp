//
// Created by Oğuz Kerem Yıldız on 23.12.2020.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Cookies/Tuple/Unit.h"
#include <iostream>

using namespace std;

TEST_CASE("Unit-test") {
    Unit<int> unit1 = Unit(3);
    Unit<int> unit2 = Unit(4);
    cout << unit1.getA() << endl;
    cout << unit1.toString() << endl;
    bool boolean = unit1 != unit2;
    cout << boolean << endl;
}