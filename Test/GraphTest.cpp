//
// Created by Oğuz Kerem Yıldız on 24.12.2020.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Cookies/Graph/Graph.h"

using namespace std;

TEST_CASE("Graph-test") {
    Graph<int> graph = Graph<int>();
    graph.addUnDirectedEdge(1, 0);
    graph.addUnDirectedEdge(2, 3);
    graph.addUnDirectedEdge(3, 4);
    graph.addUnDirectedEdge(5, 6);
    vector<Graph<int>> graphs = graph.connectedComponents();
    graph.clear();
}