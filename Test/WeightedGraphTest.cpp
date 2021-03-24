//
// Created by Oğuz Kerem Yıldız on 25.12.2020.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Cookies/Graph/WeightedGraph.h"
#include "../Cookies/Graph/IntegerLength.h"
#include "../Cookies/Graph/ResidualEdge.h"
#include <unordered_map>

using namespace std;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const
    {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

TEST_CASE("WeightedGraph-Test") {
    LengthInterface<int> *lengthInterface = new IntegerLength();
    WeightedGraph<string, int> test = WeightedGraph<string, int>(lengthInterface);
    test.addDirectedEdge("s", "a", new ResidualEdge<int>(10, lengthInterface));
    test.addDirectedEdge("s", "c", new ResidualEdge<int>(10, lengthInterface));
    test.addDirectedEdge("a", "d", new ResidualEdge<int>(8, lengthInterface));
    test.addDirectedEdge("d", "t", new ResidualEdge<int>(10, lengthInterface));
    test.addDirectedEdge("a", "b", new ResidualEdge<int>(4, lengthInterface));
    test.addDirectedEdge("a", "c", new ResidualEdge<int>(2, lengthInterface));
    test.addDirectedEdge("c", "d", new ResidualEdge<int>(9, lengthInterface));
    test.addDirectedEdge("b", "t", new ResidualEdge<int>(10, lengthInterface));
    test.addDirectedEdge("d", "b", new ResidualEdge<int>(6, lengthInterface));
    cout << "ford fulkerson: " + to_string(test.fordFulkerson("s", "t")) << endl;
    cout << "first -> ";
    cout << static_cast<ResidualEdge<int>*>(test.get("b", 0).second)->getFlow() << endl;
    static_cast<ResidualEdge<int>*>(test.get("b", 0).second)->setFlow(1);
    cout << "second -> ";
    cout << static_cast<ResidualEdge<int>*>(test.get("b", 0).second)->getFlow() << endl;
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
        cout << graph.get(key, 0).second->getLength() << endl;
    }
    unordered_map<string, pair<int, string>> map2 = graph.bellmanFord("a");
    unordered_map<string, pair<int, string>> map1 = graph.dijkstra("a");
    pair<unordered_map<int, string>, vector<vector<int>>> p = graph.floydWarshallWithKeys();
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
    vector<WeightedGraph<string, int>*> graphs = graph.connectedComponents();
    graph.clear();
    cout << "" << endl;
    WeightedGraph<pair<string, int>, int, pair_hash> g = WeightedGraph<pair<string, int>, int, pair_hash>(lengthInterface);
    g.addUndirectedEdge(pair<string, int>("Selin", 7), pair<string, int>("Oğuz", 10), 3);
    vector<pair<string, int>> v = g.getKeySet();
    cout << g.isEmpty() << endl;
    cout << g.get(pair<string, int>("Selin", 7), 0).first.first << endl;
    cout << g.containsKey(pair<string, int>("Selin", 7)) << endl;
    unordered_map<pair<string, int>, pair<int, pair<string, int>>, pair_hash> m = g.dijkstra(pair<string, int>("Selin", 7));
    vector<vector<int>> v12 = g.floydWarshall();
    cout << g.prims() << endl;
    g.addUndirectedEdge(pair<string, int>("Zeynep", 7), pair<string, int>("Mahmut", 10), 3);
    vector<WeightedGraph<pair<string, int>, int, pair_hash>*> gs = g.connectedComponents();
    g.clear();
}