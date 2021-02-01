//
// Created by Oğuz Kerem Yıldız on 1.02.2021.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Cookies/Graph/WeightedGraphEdge.h"
#include "../Cookies/Graph/IntegerLength.h"
#include <iostream>

using namespace std;

TEST_CASE("WeightedGraphEdge-test") {
    LengthInterface<int> *lengthInterface = new IntegerLength();
    WeightedGraphEdge<int, int> graph = WeightedGraphEdge<int, int>(lengthInterface);
    cout << graph.isEmpty() << endl;
    cout << graph.containsKey(4) << endl;
    graph.addUndirectedEdge(3, 2, Edge(4, lengthInterface));
    graph.addUndirectedEdge(1, 5, Edge(3, lengthInterface));
    vector<WeightedGraphEdge<int, int>> graphs = graph.connectedComponents();
    vector<int> keySet = graph.getKeySet();
    cout << graph.size() << endl;
    graph.clear();
}