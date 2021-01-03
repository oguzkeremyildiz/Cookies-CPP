//
// Created by Oğuz Kerem Yıldız on 25.12.2020.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Cookies/Graph/WeightedGraph.h"
#include "../Cookies/Graph/IntegerLength.h"
#include <unordered_map>

using namespace std;

TEST_CASE("WeightedGraph-Test") {
    LengthInterface<int> *lengthInterface = new IntegerLength();
    WeightedGraph<string, int> graph = WeightedGraph<string, int>(lengthInterface);
    graph.addUndirectedEdge("a", "b", 4);
    graph.addUndirectedEdge("a", "h", 8);
    graph.addUndirectedEdge("b", "c", 8);
    graph.addUndirectedEdge("b", "h", 11);
    graph.addUndirectedEdge("c", "d", 7);
    graph.addUndirectedEdge("c", "f", 4);
    graph.addUndirectedEdge("c", "i", 2);
    graph.addUndirectedEdge("d", "e", 9);
    graph.addUndirectedEdge("d", "f", 14);
    graph.addUndirectedEdge("e", "f", 10);
    graph.addUndirectedEdge("f", "g", 2);
    graph.addUndirectedEdge("h", "g", 1);
    for (string key : graph.getKeySet()) {
        cout << graph.get(key, 0).first << endl;
        cout << graph.get(key, 0).second << endl;
    }
    unordered_map<string, pair<int, string>> map2 = graph.bellmanFord("a");
    unordered_map<string, pair<int, string>> map1 = graph.dijkstra("a");
    int first = map1.size();
    int second = map2.size();
    int third = graph.getVertexList().size();
    if (first == second && first == third) {
        for (auto &element : map1) {
            if (element.second != map2[element.first]) {
                cout << "Warning!" << endl;
            }
        }
    } else {
        cout << "Warning!" << endl;
    }
    cout << graph.kruskal() << endl;
    graph.clear();
    graph.addUndirectedEdge("5", "8", 3);
    graph.addUndirectedEdge("7", "9", 3);
    graph.addUndirectedEdge("3", "5", 2);
    graph.addUndirectedEdge("8", "11", 45);
    vector<WeightedGraph<string, int>> graphs = graph.connectedComponents();
    graph.clear();
}