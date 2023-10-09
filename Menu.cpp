#include "Menu.h"

/**
 * Cria o menu principal e as funcionalidades do programa.
 * @return 0 Quando o programa acaba.
 */
int Menu::createMenu() {
    string file, file1, file2;
    int choice, source;
    Graph g;
    std::vector<int> path;

    drawIntro();
    g = chooseGraph();


    Algorithms algo;
    Vertex* v;
    Graph temp, clean;

    while(true) {
        printOptions();
        choice = checkValidInput();
        switch (choice) {
            case 0:
                showCredits();
                return 0;

            case 1: {
                for (auto vertex: g.getVertexSet()) {
                    temp.addVertex(vertex->getId());
                    for (auto edge: vertex->getAdj()) {
                        temp.addBidirectionalEdge(edge->getOrig()->getId(), edge->getDest()->getId(),
                                                  edge->getWeight());
                    }
                }
                TSPSolver solver(temp);
                solver.solve();
                temp = clean;
                cout << endl;
                break;
            }
            case 2:
                for (auto vertex : g.getVertexSet()){
                    temp.addVertex(vertex->getId());
                    for (auto edge: vertex->getAdj()){
                        temp.addBidirectionalEdge(edge->getOrig()->getId(), edge->getDest()->getId(), edge->getWeight());
                    }
                }
                 do{
                     cout << "Choose a number between 0 and "<< (temp.getVertexSet().size() - 1) << " for the source:" << endl;
                     source = checkValidInput();
                 }while(source > temp.getVertexSet().size() - 1);
                v = temp.findVertex(source);
                algo.TriangularApproximation(v, temp);
                temp = clean;
                break;

            case 3:
                for (auto vertex : g.getVertexSet()){
                    temp.addVertex(vertex->getId());
                    for (auto edge: vertex->getAdj()){
                        temp.addBidirectionalEdge(edge->getOrig()->getId(), edge->getDest()->getId(), edge->getWeight());
                    }
                }
                do{
                    cout << "Choose a number between 0 and "<< (temp.getVertexSet().size() - 1) << " for the source:" << endl;
                    source = checkValidInput();
                }while(source > temp.getVertexSet().size() - 1);
                v = temp.findVertex(source);
                algo.NearestNeighbor(v, temp);
                temp = clean;
                break;
            case 4:
                g = chooseGraph();
                break;

            default:
                cout << "Invalid input. Choose another option: " << endl;
                break;
        }
    }
}

/**
 * Uma função para escolher o grafo a utilizar. \n
 * @param g Um grafo.
 * @return O grafo escolhido criado.
 */

Graph Menu::chooseGraph(){
    int subDir;
    int dir;
    string file;
    FileManager f;
    Graph g;
    showHeader();
    cout << "1. Toy Graphs" << endl;
    cout << "2. Real World Graphs" << endl;
    cout << "3. Extra Fully Connected Graphs" << endl;
    dir = checkValidInput();

    switch (dir) {
        case 1:
            cout << "Type of graph" << endl;
            cout << "1. Shipping" << endl;
            cout << "2. Stadiums" << endl;
            cout << "3. Tourism" << endl;

            subDir = checkValidInput();

            if (subDir == 1) {
                g = f.readSmallGraph("shipping.csv", g);
            }
            else if (subDir == 2) {
                g = f.readSmallGraph("stadiums.csv", g);
            }
            else if (subDir == 3) {
                g = f.readSmallGraph3(g);
            }
            break;

        case 2:
            cout << "1. Graph1" << endl;
            cout << "2. Graph2" << endl;
            cout << "3. Graph3" << endl;
            subDir = checkValidInput();
            if (subDir == 1) {
                g = f.readRealWorldNodes("graph1", g);
                g = f.readRealWorldEdges("graph1", g);
            }
            else if (subDir == 2) {
                g = f.readRealWorldNodes("graph2", g);
                g = f.readRealWorldEdges("graph2", g);
            }
            else if (subDir == 3) {
                g = f.readRealWorldNodes("graph2", g);
                g = f.readRealWorldEdges("graph3", g);
            }
            break;

        case 3:
            cout << "Options: " << endl;
            cout << "edges_25.csv   |   edges_50.csv   |  edges_75.csv    |  edges_100.csv" << endl;
            cout << "edges_200.csv  |   edges_300.csv  |  edges_400.csv   |  edges_500.csv" << endl;
            cout << "edges_600.csv  |   edges_700.csv  |  edges_800.csv   |  edges_900.csv" << endl;
            cout << endl;
            cout << "File name:" << endl;
            getline(cin, file);

            g = f.readExtraFullyConnectedGraph(file, g);
            break;

        default:
            cout << "That option is invalid! Pick one of the following:" << endl;
            cout << "1. Toy Graphs" << endl;
            cout << "2. Real World Graphs" << endl;
            cout << "3. Extra Fully Connected Graphs" << endl;
            dir = checkValidInput();
            break;
    }
    return g;
}


/**
 * Faz um pedido e verificação de input e retorna-o se estiver num formato válido. \n
 * Caso contrário, continua a fazer o pedido até que o utilizador forneça um valor adequado.
 * @return Inteiro correspondente à escolha do utilizador.
 */
int Menu::checkValidInput() {
    int choice;
    cin >> choice;

    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input. Please, enter a number:" << endl;
        cin >> choice;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << endl;
    return choice;
}

/**
 * Imprime as opções do Menu.
 */
void Menu::printOptions() {
    showHeader();
    cout << "1. Backtracking Algorithm" << endl;
    cout << "2. Triangular Approximation Heuristic" << endl;
    cout << "3. Other Heuristics" << endl;
    cout << "4. Choose Other Graph" << endl;
    cout << endl;
    cout << "0. Exit and Credits" << endl;
    cout << endl;
}

/**
 * Imprime o header do menu.
 */
void Menu::showHeader() {
    cout << "================== Routing Algorithm for Ocean Shipping and Urban Deliveries Management ==================" << endl;
    cout << endl;
}

/**
 * Imprime os créditos.
 */
void Menu::showCredits() {
    cout << "Software developed by:" << endl;
    cout << "Joao Sobral" << " - " << "Joao Costa" << " - " << "Rafael Teixeira" << endl;
    cout << "G12_5" << " - " << "2LEIC12" << " - " << "DA 2022/2023" << endl;
    cout << endl;
}

void Menu::drawIntro() {
    cout << endl;
    cout << endl;
    cout << "    ^^      ..                                       ..\n"
            "            []                                       []\n"
            "          .:[]:_          ^^                       ,:[]:.\n"
            "        .: :[]: :-.                             ,-: :[]: :.\n"
            "      .: : :[]: : :`._                       ,.': : :[]: : :.\n"
            "    .: : : :[]: : : : :-._               _,-: : : : :[]: : : :.\n"
            "_..: : : : :[]: : : : : : :-._________.-: : : : : : :[]: : : : :-._\n"
            "_:_:_:_:_:_:[]:_:_:_:_:_:_:_:_:_:_:_:_:_:_:_:_:_:_:_:[]:_:_:_:_:_:_\n"
            "!!!!!!!!!!!![]!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!![]!!!!!!!!!!!!!\n"
            "^^^^^^^^^^^^[]^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^[]^^^^^^^^^^^^^\n"
            "            []                                       []\n"
            "            []                                       []\n"
            "            []                                       []\n"
            " ~~^-~^_~^~/  \\~^-~^~_~^-~_^~-^~_^~~-^~_~^~-~_~-^~_^/  \\~^-~_~^-~~-\n"
            "~ _~~- ~^-^~-^~~- ^~_^-^~~_ -~^_ -~_-~~^- _~~_~-^_ ~^-^~~-_^-~ ~^\n"
            "   ~ ^- _~~_-  ~~ _ ~  ^~  - ~~^ _ -  ^~-  ~ _  ~~^  - ~_   - ~^_~\n"
            "     ~-  ^_  ~^ -  ^~ _ - ~^~ _   _~^~-  _ ~~^ - _ ~ - _ ~~^ -\n"
            "        ~^ -_ ~^^ -_ ~ _ - _ ~^~-  _~ -_   ~- _ ~^ _ -  ~ ^-\n"
            "            ~^~ - _ ^ - ~~~ _ - _ ~-^ ~ __- ~_ - ~  ~^_-\n"
            "                ~ ~- ^~ -  ~^ -  ~ ^~ - ~~  ^~ - ~" << endl;
    cout << endl;
}

