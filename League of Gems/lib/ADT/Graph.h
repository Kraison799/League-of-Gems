//
// Created by abstractize on 13/11/18.
//

#ifndef LIB_GRAPH_H
#define LIB_GRAPH_H

#include <vector>
#include <set>
#include "Cell.h"

class Graph {
public:
    Graph(int height = 50, int width = 50, int level = 4);

private:
    int height;
    int width;
    int CantTypeObstaculos = 3;
    Cell*** keyTable;
    std::set<Cell*>*adjacencyList;
public:

    /**
     * Genera en un patron de malla en el grafo conectando de la siguiente manera
     *
     *
     *          N
     *          |
     *    O --  C -- E
     *          |
     *          S
     * Donde el centro (C) esta conectado con el nodo de arriba(N), el de abajo(S), el de la derecha(E), el de la izquierda(O)
     *
     */
    void generateGrid();
    /**
     * Funcion que restaura el valor de los puntos G y la heuristica de cada Nodo
     */
    void restoreGraph();

    /**
     * Agrega en la lista de CellFrom, el nodo CellTo
     * @param CellFrom Nodo en que se va a agregar el nodo CellTo
     * @param CellTo Nodo que se quiere agregar en CellFrom
     */
    void addEdge(Cell* CellFrom, Cell* CellTo);

    /**
     * Obtiene la lista de adyacencia del nodo en la posicion I,J
     * @param i Posicion en x en el que se encuentra el nodo
     * @param j Posicon en y en el que se encuentr el nodo
     * @return Lista de adyacencia del Nodo en (i,j)
     */
    std::set<Cell *> getNodeAdjacencyList(int i, int j);
    /**
     * Metodo que obtiene el nodo en la posicion (i,j)
     * @param i posicion x en la que se encuentra el nodo
     * @param j Posicion y en la que se encuentra el nodo
     * @return El nodo en la posicion (i,j)
     */
    Cell* getNode(int i, int j);

    int* loadMap(int lvl);

    /**
     * Destructor de la clase
     */
    virtual ~Graph();

    int getHeight() const;

    int getWidth() const;

    Cell ***getKeyTable() const;
};


#endif //LIB_GRAPH_H
