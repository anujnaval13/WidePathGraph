#include "graph.h"
#include <queue>
#include <algorithm>
#include <climits>

Graph::Graph(int n) : n(n), adjList(n) {}

void Graph::addEdge(int u, int v, int c) {
    adjList[u].emplace_back(v, c);
    adjList[v].emplace_back(u, c);
}

std::pair<int, std::vector<int>> Graph::widestPath(int s, int t) {
    std::vector<int> maxCapacity(n, 0);
    maxCapacity[s] = INT_MAX;

    std::priority_queue<std::pair<int, int>> pq;
    pq.push({INT_MAX, s});

    std::vector<int> parent(n, -1);
    
    while (!pq.empty()) {
        int currCapacity = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        for (Edge& edge : adjList[u]) {
            int v = edge.to;
            int capacity = edge.capacity;
            int newCapacity = std::min(currCapacity, capacity);

            if (newCapacity > maxCapacity[v]) {
                maxCapacity[v] = newCapacity;
                pq.push({newCapacity, v});
                parent[v] = u;
            }
        }
    }

    std::vector<int> path;
    for (int curr = t; curr != -1; curr = parent[curr]) {
        path.push_back(curr);
    }
    std::reverse(path.begin(), path.end());

    return {maxCapacity[t], path};
}
