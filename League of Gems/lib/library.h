//
// Created by gabriel on 21/10/18.
//

#ifndef LIB_LIBRARY_H __attribute__((visibility("default")));
#define LIB_LIBRARY_H

#include "Maps/Map.h"

extern "C"{
    //Prueba
    LIB_LIBRARY_H int Add(int a, int b);
    //Funciones de Mapa
    LIB_LIBRARY_H Map* getMap(int level);
    LIB_LIBRARY_H void SendPositions(Map* map, int xi, int yi, int xf, int yf);
    LIB_LIBRARY_H int GetListLenght(Map* map);
    LIB_LIBRARY_H int GetListPosition(Map* map);
}
void hello();

#endif //LIB_LIBRARY_H
