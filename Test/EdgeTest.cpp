//
// Created by Oğuz Kerem Yıldız on 1.02.2021.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Cookies/Graph/Edge.h"
#include "../Cookies/Graph/ResidualEdge.h"
#include "../Cookies/Graph/IntegerLength.h"
#include <iostream>

using namespace std;

TEST_CASE("Edge-test") {
    LengthInterface<int> *lengthInterface = new IntegerLength();
    ResidualEdge<int> edge = ResidualEdge(4, 3, lengthInterface);
    cout << edge.getFlow() << endl;
    cout << edge.getLength() << endl;
    cout << edge.getResidual() << endl;
    Edge<int> e = Edge(3);
    cout << e.getLength() << endl;
}
