#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a graph
typedef struct Graph {
    int V; // Number of vertices
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
} Graph;

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = vertices;

    // Initialize the adjacency matrix with 0s
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the undirected graph
void addEdge(Graph* graph, int u, int v) {
    if (u >= graph->V || v >= graph->V || u < 0 || v < 0) {
        printf("Invalid vertices\n");
        return;
    }
    graph->adjMatrix[u][v] = 1; // Set the edge from u to v
    graph->adjMatrix[v][u] = 1; // Set the edge from v to u (undirected)
}

// Function to display the adjacency matrix
void displayGraph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Main function to demonstrate the graph creation
int main() {
    // Create a graph with 5 vertices
    Graph* g = createGraph(5);

    // Add edges
    addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);

    // Display the adjacency matrix
    displayGraph(g);

    // Free allocated memory
    free(g);

    return 0;
}