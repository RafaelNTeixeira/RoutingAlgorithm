#ifndef DA_TRABALHO_2_FILEMANAGER_H
#define DA_TRABALHO_2_FILEMANAGER_H


#include <string>
#include <iostream>
#include <fstream>
#include "data_structures/Graph.h"
using namespace std;

class FileManager {
    public:
        Graph readRealWorldNodes(string file, Graph g);
        Graph readRealWorldEdges(string file, Graph g);
        Graph readSmallGraph(string file, Graph g);
        Graph readSmallGraph3(Graph g);
        Graph readExtraFullyConnectedGraph(string file, Graph g);
};


#endif
