//
// Created by gabriel on 21/10/18.
//

#include "Djikstra.h"



Djikstra::Djikstra(){
    graph = new Graph(50, 50, 1);
    graph->generateGrid();
}
int Djikstra::INF = 1000000;

std::list<Cell *>* Djikstra::findPath(int iStart, int jStart, int iTarget, int jTarget) {

    //Cola de prioridad que coloque el nodo con la menor distancia en eñ inicio de la cola
    std::priority_queue<Cell*, std::vector<Cell*>, CompareNode> Nodos;



    //lista con los nodos que hacen el camino
    std::list<Cell*>* path = new std::list<Cell*>();;

    //Se colocan todas las distancias en infinito, por que aun no se visitan
    setDistanceInfinite(graph);

    //Celda de inicio
    Cell* start = graph->getKeyTable()[iStart][jStart];

    //Celda final
    Cell* target = graph->getKeyTable()[iTarget][jTarget];

    //Se coloca la distancia del inicio en cero, por que el costo de moverme al inicio es cero ya que estoy ahi
    start->setDijkstraDistance(0);

    //Se coloca el inicio en la cola
    Nodos.push(start);
    while (!Nodos.empty()) {
        Cell* minCell = Nodos.top();
        Nodos.pop();

        if (minCell == target) {
            Cell* current = minCell;

            while (current != nullptr) {
                if (current == start) {
                    path->push_front(start);
                    break;
                }
                path->push_front(current);
                current = current->getPrevious();
            }

            break;
        }

        //Se adquiere una lista de los vecinos del nodo
        auto neightbors = graph->getNodeAdjacencyList(minCell->getXpos(), minCell->getYpos());

        for (Cell* neightbor : neightbors) {
            //Distancia tentativa del nodo
            int tempDistance = minCell->getDijkstraDistance() + 1;

            //Si el la distancia que posee el nodo es mayor a la tentativa se le asigna y se coloca el nodo en la cola
            if (neightbor->getDijkstraDistance() > tempDistance && neightbor->getObjectID() == 1) {

                neightbor->setDijkstraDistance(tempDistance);
                neightbor->setPrevious(minCell);
                Nodos.push(neightbor);


            }




        }

    }


    return path;



}

void Djikstra::setDistanceInfinite(Graph *graph) {
    for (int i = 0; i < graph->getHeight(); i++) {
        for (int j = 0; j < graph->getWidth(); j++) {
            graph->getKeyTable()[i][j]->setDijkstraDistance(INF);
            graph->getKeyTable()[i][j]->setPrevious(nullptr);


        }
    }
}

//Funcion para busqueda
void Djikstra::getPositions(int xi, int yi,int xf,int yf){
    auto list = findPath(xi,yi,xf,yf);
    for (auto cell : *list){
        positions.add(cell->getXpos());
        positions.add(cell->getYpos());
    }
}
