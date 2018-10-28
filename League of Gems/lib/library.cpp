//
// Created by gabriel on 21/10/18.
//

#include "library.h"
#include "Maps/Map.h"
#include "Maps/AStar.h"

#include <iostream>


//Funcion de Prueba
int Add(int a, int b) {
    return a + b;
}
//Funciones de Mapa
LIB_LIBRARY_H Map* getMap(int level){

    if (level == 1){
        std::cout<< "printing Sight Line" <<endl;
        return new AStar;
    }
    else if(level == 2){
        std::cout<< "printing Djikstra" <<endl;
        return new AStar;
    }
    else if(level == 3){
        std::cout<< "printing Kruskal" <<endl;
        return new AStar;
    }
    else if(level == 4){
        std::cout<< "printing Prim" <<endl;
        return new AStar;
    }
    else {
        std::cout<< "printing AStar" <<endl;
        return new AStar;
    }
}
LIB_LIBRARY_H void SendPositions(Map* map, int xi, int yi, int xf, int yf){
    map->getPositions(xi,yi,xf,yf);
}
LIB_LIBRARY_H int GetListLenght(Map* map){
    std::cout<< "sending list lenght..." <<endl;
    return map->sendListLenght();
}
LIB_LIBRARY_H int GetListPosition(Map* map){
    return map->sendpositionxory();
}
