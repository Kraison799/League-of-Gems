//
// Created by gabriel on 28/10/18.
//
#include "Bresenham.h"
void Bresenham::bresenham(int x1, int y1, int x2, int y2)
{
    int m_new = 2 * (y2 - y1);
    int slope_error_new = m_new - (x2 - x1);
    for (int x = x1, y = y1; x <= x2; x++)
    {
        positions.add(x);
        positions.add(y);

        // Add slope to increment angle formed
        slope_error_new += m_new;

        // Slope error reached limit, time to
        // increment y and update slope error.
        if (slope_error_new >= 0)
        {
            y++;
            slope_error_new  -= 2 * (x2 - x1);
        }
    }
}


//Funcion para busqueda
void Bresenham::getPositions(int xi, int yi,int xf,int yf){
    //Aquí obtiene los parametros inciales y finales para la busqueda
    bresenham(xi,yi,xf,yf);

}