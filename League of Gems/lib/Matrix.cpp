//
// Created by ferathor on 04/10/18.
//

#include "Matrix.h"

Matrix::Matrix(int rowSize, int columnSize) {
    this->matrix = int[rowSize][columnSize];
    this->rows = rowSize;
    this->columns = columnSize;
    while (rowSize > 0) {
        while (columnSize > 0) {
            this->matrix[rowSize][columnSize] = 0;
            columnSize--;
        }
        rowSize--;
    }
}

// Set up a int value into the matrix that will represent something
void Matrix::setState(int i, int j, int state) {
    this->matrix[i][j] = state;
}

// Return a list with arrays of two int values that represent the positions into the matrix to be taken
List<int[2]> Matrix::aSearch(int *, targetPos) {}

// Return a list with arrays of two int values that represent the positions into the matrix to be taken
List<int[2]> Matrix::dijsktra(int *, targetPos) {}

// Return a list with arrays of two int values that represent the positions into the matrix to be taken
List<int[2]> Matrix::kruskal(int *, targetPos) {}

// Return a list with arrays of two int values that represent the positions into the matrix to be taken
List<int[2]> Matrix::prim(int *, targetPos) {}