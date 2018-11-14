//
// Created by abstractize on 13/11/18.
//

#ifndef LIB_CELL_H
#define LIB_CELL_H


class Cell {
public:
    Cell(int Xpos, int Ypos, int objectID = 0);
    int getObjectID() const;
    void setObjectID(int ObjectID);
    int getXpos() const;
    int getYpos() const;
    int getHeuristic() const;
    void setHeuristic(int Heuristic);
    int getG() const;
    void setG(int g);
    Cell *getPrevious() const;
    void setPrevious(Cell *previous);
    int getHashKey() const;
    void setHashKey(int hashKey);
    bool operator < (Cell* cellToCompare);
    int getDijkstraDistance() const;
    void setDijkstraDistance(int DijkstraDistance);

private:
    int Xpos;
    int Ypos;
    int ObjectID = 0;
    int g = 10000;
    int Heuristic = 0;
    int DijkstraDistance;
    int hashKey;
    Cell* previous;
};


#endif //LIB_CELL_H
