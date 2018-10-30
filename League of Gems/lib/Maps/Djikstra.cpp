//
// Created by gabriel on 21/10/18.
//

#include "Djikstra.h"

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int Djikstra::minDistance(int *dist, bool *sptSet)
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < 16; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
};

// A utility function to print the constructed distance array
int Djikstra::printSolution(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < 16; i++)
        printf("%d tt %d\n", i, dist[i]);
};

int Djikstra::Search(List<int> a, int ele){
    for (int i = 0 ; i< a.size; i++){
        if (a.get(i) == ele){
            return a.get(i-1);
        }
    }
};

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
List<int> Djikstra::asap(List<int>  v, int src, int fin){

    List<int>  b;
    int tmp = fin;

    while (tmp != src){
        b.add(tmp);
        tmp = Search(v,tmp);
    }
    return b;
};

List<int> Djikstra::dijkstra(int src, int fin)
{
    //std::cout <<"iniciando algoritmo";
    int dist[V];     // The output array.  dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
    List<int>  a ;
    int ind=0;
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V-1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u]+graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v],
                        a.add(u),a.add(v),
                        std::cout <<u,std::cout <<" ",std::cout <<v,std::cout <<"    ";
    };


    // print the constructed distance array
    printSolution(dist, V);
    return asap(a,src,fin);
};
//Funcion para busqueda
void Djikstra::getPositions(int xi, int yi,int xf,int yf){
    //Aquí obtiene los parametros inciales y finales para la busqueda
}
