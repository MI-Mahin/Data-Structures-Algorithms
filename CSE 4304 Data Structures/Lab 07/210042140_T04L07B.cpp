#include <iostream>
#include <set>

class Graph {
private:
    int n;
    int** adj;
    bool* visited;

public:
    Graph(int nodes) : n(nodes) {
        adj = new int*[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new int[n]();
        }
        visited = new bool[n]();
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;  // For undirected graph
    }

    void dfs(int node, std::set<int>& component) {
        visited[node] = true;
        component.insert(node);

        for (int neighbor = 0; neighbor < n; neighbor++) {
            if (adj[node][neighbor] == 1 && !visited[neighbor]) {
                dfs(neighbor, component);
            }
        }
    }

    std::set<std::set<int>> findConnectedComponents() {
        std::set<std::set<int>> components;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                std::set<int> component;
                dfs(i, component);
                components.insert(component);
            }
        }
        return components;
    }

    ~Graph() {
        for (int i = 0; i < n; i++) {
            delete[] adj[i];
        }
        delete[] adj;
        delete[] visited;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;

    Graph graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        graph.addEdge(u - 1, v - 1);  // Adjust for 0-based indexing
    }

    std::set<std::set<int>> components = graph.findConnectedComponents();

    std::cout << "Components: " << components.size() << std::endl;
    std::cout << "Component sets:" << std::endl;
    for (const std::set<int>& component : components) {
        std::cout << "{";
        for (int node : component) {
            std::cout << node + 1 << " ";  // Adjust for 0-based indexing
        }
        std::cout << "}" << std::endl;
    }

    return 0;
}

