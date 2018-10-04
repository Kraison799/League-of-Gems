//
// Created by ferathor on 04/10/18.
//

#include "List.h"
#ifndef LEAGUEOFGEMS_MATRIX_H
#define LEAGUEOFGEMS_MATRIX_H
#define NULL 0;

class Matrix {
public:
    Matrix();
    List<int[2]> aSearch(int[2] targetPos);
    List<int[2]> dijsktra(int[2] targetPos)
    List<int[2]> kruskal(int[2] targetPos);
    List<int[2]> prim(int[2] targetPos);
    void setState(int i, int j, int state);
private:
    int[][] matrix;
};

#endif //LEAGUEOFGEMS_MATRIX_H
