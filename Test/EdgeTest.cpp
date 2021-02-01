//
// Created by Oğuz Kerem Yıldız on 1.02.2021.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Cookies/Graph/Edge.h"
#include "../Cookies/Graph/IntegerLength.h"
#include <iostream>

using namespace std;

TEST_CASE("Edge-test") {
    LengthInterface<int> *lengthInterface = new IntegerLength();
    Edge<int> edge = Edge(4, 3, lengthInterface);
    cout << edge.getFlow() << endl;
    cout << edge.getCapacity() << endl;
    cout << edge.getResidual() << endl;
}
