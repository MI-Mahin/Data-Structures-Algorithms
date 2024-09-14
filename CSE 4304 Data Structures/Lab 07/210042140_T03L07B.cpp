#include <iostream>

class DSU {
private:
    int* parent;
    int* rank;

public:
    DSU(int n) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x != y) {
            if (rank[x] < rank[y]) {
                parent[x] = y;
            } else if (rank[x] > rank[y]) {
                parent[y] = x;
            } else {
                parent[y] = x;
                rank[x]++;
            }
        }
    }

    ~DSU() {
        delete[] parent;
        delete[] rank;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;

    DSU dsu(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        dsu.unite(u - 1, v - 1); // Adjust for 0-based indexing
    }

    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        int x, y;
        std::cin >> x >> y;
        if (dsu.find(x - 1) == dsu.find(y - 1)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}
