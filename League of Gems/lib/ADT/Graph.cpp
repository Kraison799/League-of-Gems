//
// Created by abstractize on 13/11/18.
//

#include "Graph.h"


Graph::Graph(int height, int width, int level) {

    int key = 0;
    Cell* currentCell = nullptr;
    //srand(time(nullptr));
    auto map = this->loadMap(level);
    //Determina el tamaño del grafo
    this->height = height;
    this->width = width;
    //Determina el tamaño del array de las listas de adyacencia
    this->adjacencyList = new std::set<Cell*>[this->height * this->width];

    this->keyTable = new Cell**[this->height];
    for (int i = 0; i < this->height; ++i) {

        this->keyTable[i] = new Cell*[this->width];

        for (int j = 0; j < this->width; j++) {

            currentCell = new Cell(i, j);
            this->keyTable[i][j] = currentCell;
            currentCell->setHashKey(key);
            currentCell->setObjectID(map[key]);

            //Aumenta la llave del siguiente elemento
            key++;


        }

    }
    delete(map);

}

void Graph::generateGrid() {
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {

            if (i - 1 > 0) {

                addEdge(this->keyTable[i][j], this->keyTable[i - 1][j]);
                addEdge(this->keyTable[i - 1][j], this->keyTable[i][j]);

            }
            if (i + 1 < this->height) {

                addEdge(this->keyTable[i][j], this->keyTable[i + 1][j]);
                addEdge(this->keyTable[i + 1][j], this->keyTable[i][j]);

            }
            if (j - 1 > 0) {

                addEdge(this->keyTable[i][j], this->keyTable[i][j - 1]);
                addEdge(this->keyTable[i][j - 1], this->keyTable[i][j]);

            }
            if (j + 1 < this->width) {

                addEdge(this->keyTable[i][j], this->keyTable[i][j + 1]);
                addEdge(this->keyTable[i][j + 1], this->keyTable[i][j]);

            }

        }
    }
}

void Graph::restoreGraph() {
    Cell* currentCell;

    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            currentCell = this->keyTable[i][j];

            currentCell->setG(10000);
            currentCell->setHeuristic(0);

        }
    }

}

void Graph::addEdge(Cell *CellFrom, Cell *CellTo) {
    int keyFrom = CellFrom->getHashKey();
    this->adjacencyList[keyFrom].insert(CellTo);



}

int* Graph::loadMap(int lvl) {
    FILE *myFile;
    myFile = fopen("level.txt", "r");

    //read file into array
    int* numberArray;
    numberArray = new int[2500];
    int i;

    if (myFile == NULL) {
        printf("Error Reading File\n");
        exit(0);
    }

    for (i = 0; i < 2500; i++) {
        fscanf(myFile, "%d,", &numberArray[i]);
    }

    fclose(myFile);

    return numberArray;
}

Graph::~Graph() {

    //TODO: Desarrollar el destructor

}

std::set<Cell *> Graph::getNodeAdjacencyList(int i, int j) {
    int key = this->keyTable[i][j]->getHashKey();
    return this->adjacencyList[key];
}

Cell *Graph::getNode(int i, int j) {
    return this->keyTable[i][j];
}

int Graph::getHeight() const {
    return height;
}

int Graph::getWidth() const {
    return width;
}

Cell ***Graph::getKeyTable() const {
    return keyTable;
}