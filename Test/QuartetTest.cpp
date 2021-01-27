//
// Created by Oğuz Kerem Yıldız on 28.01.2021.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Cookies/Tuple/Quartet.h"
#include <iostream>

using namespace std;

TEST_CASE("Quartet-test") {
    Quartet<int, int, int, int> quartet1 = Quartet<int, int, int, int>(1, 2, 3, 4);
    Quartet<int, int, int, int> quartet2 = Quartet<int, int, int, int>(1, 8, 3, 4);
    cout << quartet1.getC() << endl;
    bool boolean = quartet1 != quartet2;
    cout << boolean << endl;
}
