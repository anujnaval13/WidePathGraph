#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "graph.h"

void runTestCase(const std::string& filename) {
    std::ifstream infile(filename);
    int n, m;
    infile >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; ++i) {
        int u, v, c;
        infile >> u >> v >> c;
        g.addEdge(u, v, c);
    }

    int s, t;
    infile >> s >> t;

    auto result = g.widestPath(s, t);
    int maxCapacity = result.first;
    std::vector<int> path = result.second;

    std::cout << "Test Case: " << filename << std::endl;
    std::cout << "Maximum packet size: " << maxCapacity << std::endl;
    std::cout << "Path: ";
    for (int v : path) {
        std::cout << v << " ";
    }
    std::cout << std::endl << std::endl;
}

int main() {
    std::vector<std::string> testFiles = {"test/test1.txt", "test/test2.txt", "test/test3.txt", "test/test4.txt", "test/test5.txt", "test/test6.txt", "test/test7.txt", "test/test8.txt"};
    for (const std::string& testFile : testFiles) {
        runTestCase(testFile);
    }
    return 0;
}
