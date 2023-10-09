#ifndef DA_TRABALHO_2_MENU_H
#define DA_TRABALHO_2_MENU_H

#include "data_structures/Graph.h"
#include "data_structures/VertexEdge.h"
#include "FileManager.h"
#include "Algorithms.h"
using namespace std;

class Menu {
    public:
        int createMenu();
        int checkValidInput();
        Graph chooseGraph();
        void printOptions();
        void showHeader();
        void showCredits();
        void drawIntro();


};


#endif
