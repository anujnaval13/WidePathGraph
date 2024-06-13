#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <utility>

#include "edge.h"

class Graph {
public:
    Graph(int n);
    void addEdge(int u, int v, int c);
    std::pair<int, std::vector<int>> widestPath(int s, int t);

private:
    int n;
    std::vector<std::vector<Edge>> adjList;
};

#endif // GRAPH_H
