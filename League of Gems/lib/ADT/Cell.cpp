//
// Created by abstractize on 13/11/18.
//

#include "Cell.h"

Cell::Cell(int Xpos, int Ypos, int objectID) :Xpos(Xpos), Ypos(Ypos) {
    this->previous = nullptr;
}


int Cell::getObjectID() const {
    return ObjectID;
}

void Cell::setObjectID(int ObjectID) {
    Cell::ObjectID = ObjectID;
}

int Cell::getXpos() const {
    return Xpos;
}

int Cell::getYpos() const {
    return Ypos;
}

int Cell::getHeuristic() const {
    return Heuristic;
}

void Cell::setHeuristic(int Heuristic) {
    Cell::Heuristic = Heuristic;
}

int Cell::getG() const {
    return g;
}

void Cell::setG(int g) {
    Cell::g = g;
}

Cell *Cell::getPrevious() const {
    return previous;
}


void Cell::setPrevious(Cell *previous) {
    Cell::previous = previous;
}



int Cell::getHashKey() const {
    return hashKey;
}

void Cell::setHashKey(int hashKey) {
    Cell::hashKey = hashKey;
}

bool Cell::operator<(Cell *cellToCompare) {
    return this->DijkstraDistance > cellToCompare->DijkstraDistance;
}

int Cell::getDijkstraDistance() const {
    return DijkstraDistance;
}

void Cell::setDijkstraDistance(int DijkstraDistance) {
    Cell::DijkstraDistance = DijkstraDistance;
}
bool Cell::isVisited() const {
    return visited;
}
void Cell::setVisited(bool pVisit) {
    Cell::visited = pVisit;
}
bool Cell::operator==(const Cell &cellToCompare) const {
    return this->getXpos() == cellToCompare.getXpos() && this->getYpos() ==cellToCompare.getYpos();
}