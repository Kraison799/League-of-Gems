//
// Created by gabriel on 21/10/18.
//

#ifndef LIB_LIBRARY_H __attribute__((visibility("default")));
#define LIB_LIBRARY_H

extern "C"{
    //Prueba
    LIB_LIBRARY_H int Add(int a, int b);
    //Funciones de Mapa
    LIB_LIBRARY_H void SendListAdder(void(*action)(int x,int y));
    LIB_LIBRARY_H void SendPositions(float xi,float yi,float xf, float yf);
}
void hello();

#endif //LIB_LIBRARY_H
