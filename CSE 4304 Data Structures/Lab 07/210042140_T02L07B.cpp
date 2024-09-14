#include <iostream>

void displayAdjacencyList(int** adjList, int n) {
    std::cout << "List view:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << " -> ";
        for (int j = 0; j < n; j++) {
            if (adjList[i][j] == 1) {
                std::cout << j + 1 << " ";
            }
        }
        std::cout << std::endl;
    }
}

void displayAdjacencyMatrix(int** adjMatrix, int n) {
    std::cout << "\nMatrix view:" << std::endl;
    std::cout << "  ";
    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < n; j++) {
            std::cout << (adjMatrix[i][j] == 1 ? "x " : "  ");
        }
        std::cout << std::endl;
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;

    // Initialize the adjacency list and adjacency matrix
    int** adjList = new int*[n];
    int** adjMatrix = new int*[n];

    for (int i = 0; i < n; i++) {
        adjList[i] = new int[n]();
        adjMatrix[i] = new int[n]();
    }

    // Input edges and build the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;  // Adjust for 0-based indexing
        v--;

        adjList[u][v] = 1;
        adjList[v][u] = 1;

        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    // Display the adjacency list and adjacency matrix
    displayAdjacencyList(adjList, n);
    displayAdjacencyMatrix(adjMatrix, n);

    // Deallocate memory
    for (int i = 0; i < n; i++) {
        delete[] adjList[i];
        delete[] adjMatrix[i];
    }
    delete[] adjList;
    delete[] adjMatrix;

    return 0;
}

