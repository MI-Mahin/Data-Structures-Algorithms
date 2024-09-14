#include <iostream>
#include <functional>

int main() {
    int n, m;
    std::cin >> n >> m;

    int adj[101][101] = {0};  // Adjacency matrix representation
    bool visited[101] = {false};

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }

    std::pair<int, int> treeEdges[100];  // Edges of the tree

    // DFS to obtain a tree
    std::function<void(int)> dfs = [&](int node) {
        visited[node] = true;
        for (int neighbor = 1; neighbor <= n; ++neighbor) {
            if (adj[node][neighbor] && !visited[neighbor]) {
                treeEdges[node - 2] = {node, neighbor};
                dfs(neighbor);
            }
        }
    };

    dfs(1);  // Start DFS from any arbitrary node (here, 1)

    // Output the edges of the tree
    for (int i = 0; i < n - 1; ++i) {
        std::cout << treeEdges[i].first << " " << treeEdges[i].second << "\n";
    }

    return 0;
}

