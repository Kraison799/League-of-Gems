//
// Created by gabriel on 21/10/18.
//

#include "library.h"
#include "Maps/Map.h"
#include "Maps/Djikstra.h"

#include <iostream>

Djikstra a;
List<int> PosList;

int Add(int a, int b) {
    return a + b;
}


void SendListAdder(void(*action)(int,int)){
    for(int i = 0; i<PosList.size;i++){
        //Conversion de nodo a x y
        int x = PosList.get(i)%250;
        int y = PosList.get(i)/250;
        action(x,y);
    }

}
void SendPositions(int xi,int yi,int xf, int yf){
    //Conversion de x y a nodo
    int init = xi*(1+yi) +xi;
    int finit = xf*(1+yf) +xf;
    PosList = a.dijkstra(init,finit);
}