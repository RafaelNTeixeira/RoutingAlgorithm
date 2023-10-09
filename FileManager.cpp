#include "FileManager.h"

/**
 * Abre um file com os nodes de um grafo. \n
 * Time Complexity: O(n1*V); [n1 = número de nodes a serem lidas]
 * @param file Uma "string" que corresponde ao nome do diretório com o grafo.
 * @param g Um grafo.
 * @return Grafo a utilizar na programa.
 */
Graph FileManager::readRealWorldNodes(string file, Graph g) {
    string skip, id, longitude, latitude;
    int id_;
    ifstream filename;
    filename.open("../Project2Graphs/Real-world Graphs/" + file + "/nodes.csv");
    if (!filename.is_open()) cout << "File creation failed" << endl;
    else {
        if (!filename.eof()) { getline(filename, skip, ',');}
        if (!filename.eof()) { getline(filename, skip, ',');}
        if (!filename.eof()) { getline(filename, skip,  '\n');}

        while (!filename.eof()) {
            getline(filename, id, ',');
            getline(filename, longitude, ',');
            getline(filename, latitude, '\n');
            id_ = stoi(id); //O(N)
            g.addVertex(id_);
        }
    }
    return g;
}

/**
 * Abre um file com as edges de um grafo. \n
 * Time Complexity: O(n2*V); [n2 = número de edges a serem lidas]
 * @param file Uma "string" que corresponde ao nome do diretório com o grafo.
 * @param g Um grafo.
 * @return Grafo a utilizar na programa.
 */
Graph FileManager::readRealWorldEdges(string file, Graph g) {
    string skip, source, dest, weight;
    int idSource, idDest;
    double weight_;
    ifstream filename;
    filename.open("../Project2Graphs/Real-world Graphs/" + file + "/edges.csv");
    if (!filename.is_open()) cout << "File creation failed" << endl;
    else {
        if (!filename.eof()) { getline(filename, skip, ',');}
        if (!filename.eof()) { getline(filename, skip, ','); }
        if (!filename.eof()) { getline(filename, skip, ','); }
        if (!filename.eof()) { getline(filename, skip, '\n'); }

        while (!filename.eof()) {
            getline(filename, source, ',');
            getline(filename, dest, ',');
            getline(filename, weight, '\n');
            idSource = stoi(source);
            idDest = stoi(dest);
            weight_ = stod(weight);
            g.addBidirectionalEdge(idSource, idDest, weight_); // O(V)
        }
    }
    return g;
}

/**
 * Abre um file com os edges dos grafos mais curtos. \n
 * Time Complexity: O(n1*V); [n1 = número de edges a serem lidos]
 * @param file Uma "string" que corresponde ao nome do ficheiro onde estão as edges.
 * @param g Um grafo.
 * @return Grafo a utilizar na programa.
 */

Graph FileManager::readSmallGraph(string file, Graph g) {
    string source, dest, weight, skip;
    int idSource, idDest;
    ifstream filename;
    filename.open("../Project2Graphs/Toy-Graphs/" + file);
    if (!filename.is_open()) cout << "File creation failed" << endl;
    else {
        if (!filename.eof()) { getline(filename, skip, ',');}
        if (!filename.eof()) { getline(filename, skip, ',');}
        if (!filename.eof()) { getline(filename, skip,  '\n');}

        while (!filename.eof()) {
            getline(filename, source, ',');
            getline(filename, dest, ',');
            getline(filename, weight, '\n');

            idSource = stoi(source);
            idDest = stoi(dest);

            if (g.findVertex(idSource) == nullptr){
                g.addVertex(idSource);
            }
            if (g.findVertex(idDest) == nullptr){
                g.addVertex(idDest);
            }
            g.addBidirectionalEdge(idSource, idDest, stod(weight));
        }
    }
    return g;
}

/**
 * Abre um file com os edges do grafo mais curto "tourism.csv". \n
 * Time Complexity: O(n1*V); [n1 = número de edges a serem lidas]
 * @param file Uma "string" que corresponde ao nome do ficheiro de egdes.
 * @param g Um grafo.
 * @return Grafo a utilizar na programa.
 */
Graph FileManager::readSmallGraph3(Graph g) {
    string source, dest, weight, skipLabelSource, skipLabelDest, skip;
    int idSource, idDest;
    ifstream filename;
    filename.open("../Project2Graphs/Toy-Graphs/tourism.csv");
    if (!filename.is_open()) cout << "File creation failed" << endl;
    else {
        if (!filename.eof()) { getline(filename, skip, ',');}
        if (!filename.eof()) { getline(filename, skip, ',');}
        if (!filename.eof()) { getline(filename, skip, ',');}
        if (!filename.eof()) { getline(filename, skip, ',');}
        if (!filename.eof()) { getline(filename, skip,  '\n');}

        while (!filename.eof()) {
            getline(filename, source, ',');
            getline(filename, dest, ',');
            getline(filename, weight, ',');
            getline(filename, skipLabelSource, ',');
            getline(filename, skipLabelDest, '\n');

            idSource = stoi(source);
            idDest = stoi(dest);

            if (g.findVertex(idSource) == nullptr){
                g.addVertex(idSource);
            }
            if (g.findVertex(idDest) == nullptr){
                g.addVertex(idDest);
            }
            g.addBidirectionalEdge(idSource, idDest, stod(weight));
        }
    }
    return g;
}

/**
 * Abre um file com as edges de um grafo Extra Fully Connected. \n
 * Time Complexity: O(n1*V); [n1 = número de edges a serem lidas]
 * @param file Uma "string" que corresponde ao nome do ficheiro de edges.
 * @param g Um grafo.
 * @return Grafo a utilizar na programa.
 */
Graph FileManager::readExtraFullyConnectedGraph(string file, Graph g) {
    string source, dest, weight, skip;
    int idSource, idDest;
    ifstream filename;
    filename.open("../Project2Graphs/Extra_Fully_Connected_Graphs/" + file);
    if (!filename.is_open()) cout << "File creation failed" << endl;
    else {
        if (!filename.eof()) { getline(filename, skip, ',');}
        if (!filename.eof()) { getline(filename, skip, ',');}
        if (!filename.eof()) { getline(filename, skip,  '\n');}

        while (!filename.eof()) {
            getline(filename, source, ',');
            getline(filename, dest, ',');
            getline(filename, weight, '\n');

            idSource = stoi(source);
            idDest = stoi(dest);

            if (g.findVertex(idSource) == nullptr){
                g.addVertex(idSource);
            }
            if (g.findVertex(idDest) == nullptr){
                g.addVertex(idDest);
            }
            g.addBidirectionalEdge(idSource, idDest, stod(weight));
        }
    }
    return g;
}


