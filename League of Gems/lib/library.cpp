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
        int x;
        int y;
        action(x,y);
    }

}
void SendPositions(float xi,float yi,float xf, float yf){
    //Conversion de x y a nodo
    PosList = a.dijkstra(25,20);
}