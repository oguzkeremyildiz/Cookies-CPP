//
// Created by Oğuz Kerem Yıldız on 24.12.2020.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Cookies/Graph/Graph.h"
#include <utility>

using namespace std;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const
    {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

TEST_CASE("Graph-test") {
    Graph<int> graph = Graph<int>();
    graph.addUnDirectedEdge(1, 0);
    graph.addUnDirectedEdge(2, 3);
    graph.addUnDirectedEdge(3, 4);
    graph.addUnDirectedEdge(5, 6);
    vector<Graph<int>> graphs = graph.connectedComponents();
    graph.clear();
    Graph<pair<int, int>, pair_hash> g = Graph<pair<int, int>, pair_hash>();
    g.addUnDirectedEdge(pair<int, int>(3, 4), pair<int, int>(3, 6));
    g.addUnDirectedEdge(pair<int, int>(7, 34), pair<int, int>(2, 54));
    g.addUnDirectedEdge(pair<int, int>(7, 34), pair<int, int>(3, 4));
    cout << g.contains(pair<int, int>(3, 6)) << endl;
    cout << g.size() << endl;
    vector<Graph<pair<int, int>, pair_hash>> gs = g.connectedComponents();
    vector<pair<int, int>> v = g.getKeySet();
    unordered_set<pair<int, int>, pair_hash> set = g.getVertexList();
    g.clear();
}