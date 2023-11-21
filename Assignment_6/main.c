#include <stdio.h>
#include <stdlib.h>
#include"graph.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./graph <input_file>\n");
        return 1;
    }

    char *inputFile = argv[1];
    FILE *file = fopen(inputFile, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int numVertices;
    fscanf(file, "%d", &numVertices);

    Graph *graph = createGraph(numVertices);

    readAdjMatrix(graph, file);

    fclose(file);

    int choice;
    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayGraph(graph);
                break;
            case 2:
                displayDegree(graph);
                break;
            case 3:
                if (isConnected(graph)) {
                    printf("The graph is connected.\n");
                } else {
                    printf("The graph is not connected.\n");
                }
                break;
            case 4:
                displayComponents(graph);
                break;
            case 5: {
                int source, destination;
                printf("Enter two vertices to check adjacency: ");
                scanf("%d %d", &source, &destination);
                if (isAdjacent(graph, source, destination)) {
                    printf("Vertex %d and Vertex %d are adjacent.\n", source, destination);
                } else {
                    printf("Vertex %d and Vertex %d are not adjacent.\n", source, destination);
                }
                break;
            }
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    freeGraph(graph);

    return 0;
}
