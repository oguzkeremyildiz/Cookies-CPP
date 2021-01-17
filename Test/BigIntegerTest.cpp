//
// Created by Oğuz Kerem Yıldız on 17.01.2021.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Cookies/Util/BigInteger.h"
#include <vector>

using namespace std;

TEST_CASE("BigIntegerTest-test") {
    BigInteger b = BigInteger("89795");
    BigInteger a = BigInteger("454030");
    BigInteger c = BigInteger(454030);
    c *= "974500945974";
    cout << c.value() << endl;
    b += "463638989";
    a -= "546745";
    if (b > a) {
        cout << "b > a" << endl;
    }
    BigInteger b1 = BigInteger(-3000);
    BigInteger b2 = BigInteger(-4000);
    if (b1 != b2) {
        cout << "correct" << endl;
    }
    cout << b.value() << endl;
    cout << a.value() << endl;
}