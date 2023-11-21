#include <stdio.h>
#include <stdlib.h>
#include"graph.h"

Graph* createGraph(int numVertices) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    graph->adjMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (int*)calloc(numVertices, sizeof(int));
    }

    return graph;
}

void readAdjMatrix(Graph *graph, FILE *file) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            fscanf(file, "%d", &graph->adjMatrix[i][j]);
        }
    }
}

void displayGraph(Graph *graph) {
    printf("Graph (Adjacency Matrix):\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void displayDegree(Graph *graph) {
    printf("Degree of each vertex:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        int degree = 0;
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjMatrix[i][j] != 0) {
                degree++;
            }
        }
        printf("Vertex %d: %d\n", i, degree);
    }
}

int isConnected(Graph *graph) {
    int visited[graph->numVertices];
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    int queue[graph->numVertices];
    int front = 0, rear = 0;

    visited[0] = 1;
    queue[rear++] = 0;

    while (front != rear) {
        int currentVertex = queue[front++];
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] != 0 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    for (int i = 0; i < graph->numVertices; i++) {
        if (visited[i] == 0) {
            return 0;
        }
    }

    return 1;
}

void DFS(Graph *graph, int vertex, int visited[], int component[], int componentNum, int componentVertices[][100], int *componentSize) {
    visited[vertex] = 1;
    component[vertex] = componentNum;
    componentVertices[componentNum][(*componentSize)++] = vertex;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] != 0 && visited[i] == 0) {
            DFS(graph, i, visited, component, componentNum, componentVertices, componentSize);
        }
    }
}

void displayComponents(Graph *graph) {
    int visited[graph->numVertices];
    int component[graph->numVertices];
    int componentNum = 1;

    printf("Components in the Graph:\n");

    int componentVertices[100][100];
    int componentSizes[100] = {0};

    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
        component[i] = -1;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        if (visited[i] == 0) {
            int componentSize = 0;
            DFS(graph, i, visited, component, componentNum, componentVertices, &componentSize);
            componentSizes[componentNum] = componentSize;
            componentNum++;
        }
    }

    for (int i = 1; i < componentNum; i++) {
        printf("Component %d: ", i);
        for (int j = 0; j < componentSizes[i]; j++) {
            printf("%d ", componentVertices[i][j]);
        }
        printf("\n");
    }
}

int isAdjacent(Graph *graph, int vertex1, int vertex2) {
    if (graph->adjMatrix[vertex1][vertex2] != 0 || graph->adjMatrix[vertex2][vertex1] != 0) {
        return 1;
    }
    return 0;
}

void menu() {
    printf("\nGraph Operations:\n");
    printf("1. Display Graph\n");
    printf("2. Display Degree of each vertex\n");
    printf("3. Verify if the graph is connected\n");
    printf("4. Display number of components in the Graph and vertices in each component\n");
    printf("5. Check if one vertex is adjacent to another\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

