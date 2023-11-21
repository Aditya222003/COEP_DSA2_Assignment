#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int numVertices;
    int **adjMatrix;
} Graph;


Graph* createGraph(int numVertices) ;

void readAdjMatrix(Graph *graph, FILE *file) ;

void displayGraph(Graph *graph) ;

void displayDegree(Graph *graph) ;

int isConnected(Graph *graph) ;    

void DFS(Graph *graph, int vertex, int visited[], int component[], int componentNum, int componentVertices[][100], int *componentSize) ;

void displayComponents(Graph *graph) ;

int isAdjacent(Graph *graph, int vertex1, int vertex2) ;

void menu() ;

void freeGraph(Graph *graph) ;