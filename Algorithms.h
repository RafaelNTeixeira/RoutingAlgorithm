#ifndef DA_TRABALHO_2_ALGORITHMS_H
#define DA_TRABALHO_2_ALGORITHMS_H

#include "data_structures/Graph.h"
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <sstream>

using namespace std;

class Algorithms {
    public:
        void TriangularApproximation(Vertex* source, Graph g);
        void NearestNeighbor(Vertex* source, Graph g);
        void PathDfs(Vertex* source, Graph g, vector<int> &path);

};


class TSPSolver {
    public:
        TSPSolver(const Graph& g) : graph(g), bestCost(std::numeric_limits<double>::max()) {}
        void solve();
        vector<int> bestPath;
        double bestCost;

    private:
        Graph graph;
        void backtrack(vector<int>& path, double cost);
        double calculateEdgeCost(int source, int destination) const;
};

#endif
