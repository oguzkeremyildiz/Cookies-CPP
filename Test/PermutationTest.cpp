//
// Created by Oğuz Kerem Yıldız on 25.12.2020.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Cookies/Util/Permutation.h"
#include <iostream>

using namespace std;

TEST_CASE("Permutation-test") {
    Permutation p = Permutation(5);
    while (p.next()) {
        int *n = p.get();
        for (int i = 0; i < 5; ++i) {
            cout << n[i];
        }
        cout << "" << endl;
    }
}