#include "Algorithms.h"

/**
 * Uma struct para usar na fila para ordenar os edges em ordem decrescente. \n
 */
struct CompareEdge {
    bool operator()(Edge* const& e1, Edge* const& e2) {
        return e1->getWeight() > e2->getWeight();
    }
};

/**
 * O algoritmo começa pelo node selecionado e guarda o caminho cujos edges estão selecionados. \n
 * Time Complexity: O(V + E)
 * @param source Um pointer para o vértice source.
 * @param g Um grafo.
 * @param path A referência para um vetor de int's que corresponde a um caminho
 */
void Algorithms::PathDfs(Vertex* source, Graph g, vector<int> &path){

    for (auto ele : source->getAdj()){
        if (ele->isSelected()){
            path.push_back(ele->getDest()->getId());
            PathDfs(ele->getDest(), g, path);
        }
    }
}

/**
 * A partir de um node source, determina a MST do grafo e com ela calcula o menor caminho possível. \n
 * Time Complexity: O(V + E)
 * @param source Um pointer para o vértice source.
 * @param g Um grafo.
 */
void Algorithms::TriangularApproximation(Vertex* source, Graph g){

    vector<int> path;
    int cost = 0;
    priority_queue<Edge*, vector<Edge*>, CompareEdge> queue;
    source->setVisited(true);
    path.push_back(source->getId());

    for (auto ele : source->getAdj()){
        queue.push(ele);
    }

    while (!queue.empty()){
        if (queue.top()->getDest()->isVisited()){
            queue.pop();
        }
        else{
            queue.top()->getDest()->setVisited(true);
            queue.top()->setSelected(true);
            Vertex* temp = queue.top()->getDest();

            queue.pop();

            for (auto ele : temp->getAdj()){
                if (ele->getDest()->isVisited()) continue;
                queue.push(ele);
            }
        }
    }

    PathDfs(source, g, path);

    for (auto ele: path){
        cout << ele << "->";
    }
    path.push_back(source->getId());
    cout << path[0] << endl;


    for (int i = 0; i < path.size() - 1; i++){
        Vertex* src = g.findVertex(path[i]);
        Vertex* dest = g.findVertex(path[i+1]);
        for (auto ele : src->getAdj()){
            if (ele->getDest() == dest) {
                cost += ele->getWeight();
                break;
            }
        }
    }

    cout << "Cost: " << cost << endl;
}

/**
 * Escolhe sempre o caminho com o menor custo possível. \n
 * Time Complexity: O(V*E)
 * @param source Um pointer para o vértice source.
 * @param g Um grafo.
 */
void Algorithms::NearestNeighbor(Vertex* source, Graph g){

    vector<int> path;
    path.push_back(source->getId());
    source->setVisited(true);
    Vertex* curr_vertex = source;
    bool allNodesVisited = false;
    int cost = 0;

    while (true) {
        priority_queue<Edge*, vector<Edge*>, CompareEdge> queue;

        for (auto ele : curr_vertex->getAdj()){
            queue.push(ele);
        }

        while (queue.top()->getDest()->isVisited()){
            queue.pop();
            if (queue.empty()){
                allNodesVisited = true;
                break;
            }
        }

        if (allNodesVisited) break;

        curr_vertex = queue.top()->getDest();
        cost += queue.top()->getWeight();
        path.push_back(curr_vertex->getId());
        curr_vertex->setVisited(true);
    }

    for (auto ele : path){
        cout << ele << "->";
    }
    cout << path[0] << endl;

    Vertex* src = g.findVertex(path[0]);
    Vertex* dest = g.findVertex(path[path.size() -1]);
    for (auto ele : src->getAdj()){
        if (ele->getDest() == dest) {
            cost += ele->getWeight();
            break;
        }
    }
    cout << "Cost: " << cost << endl;
}


/**
 * Dá a solução para o problema do TSP. \n
 * Time Complexity: O((N-1)!)
 * Este método encontra o melhor caminho que visita todos os vértices num grafo e que retorna para o vértice inicial.
 */
void TSPSolver::solve() {
    vector<int> path;
    path.push_back(0);
    Vertex* v = graph.findVertex(0);
    v->setVisited(true);

    backtrack(path, 0.0);

    cout << "Best Path: ";
    for (int vertex : bestPath) {
        cout << vertex << "->";
    }
    cout << bestPath.front();
    cout << endl;
    cout << "Best Cost: " << bestCost << endl;
}

/**
 * Usado para encontrar o melhor caminho recorrendo a estratégias de backtracking e bounding. \n
 * Time Complexity: O((N-1)!)
 * @param path O caminho que está atualemente a ser percorrido.
 * @param cost O custo do caminho atual.
 */
void TSPSolver::backtrack(vector<int>& path, double cost) {
    if (path.size() == graph.getNumVertex()) {
        double currentCost = cost + calculateEdgeCost(path.back(), path.front());
        if (currentCost < bestCost) {
            bestPath = path;
            bestCost = currentCost;
        }
        return;
    }

    int lastVertex = path.back();
    for (const auto& vertex : graph.getVertexSet()) {
        int nextVertex = vertex->getId();
        if (!vertex->isVisited() && cost + calculateEdgeCost(lastVertex, nextVertex) < bestCost) {
            vertex->setVisited(true);
            path.push_back(nextVertex);
            backtrack(path, cost + calculateEdgeCost(lastVertex, nextVertex));
            path.pop_back();
            vertex->setVisited(false);
        }
    }
}

/**
 * Calcula o custo de um edge entre dois vértices. \n
 * Time Complexity: O(N)
 * @param source O ID do vértice source.
 * @param destination O ID do vértice destination.
 * @return O custo do edge ou um valor infinito para o caso de o edge não existir.
 */
double TSPSolver::calculateEdgeCost(int source, int destination) const {
    Vertex* sourceVertex = graph.findVertex(source);
    Vertex* destVertex = graph.findVertex(destination);
    if (sourceVertex && destVertex) {
        for (const auto& edge : sourceVertex->getAdj()) {
            if (edge->getDest()->getId() == destination) {
                return edge->getWeight();
            }
        }
    }
    return numeric_limits<double>::infinity();
}

