#include <iostream>
#include <vector>

#define MAXN 100005

int parent[MAXN];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) parent[x] = y;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    // Initializing parent array for disjoint set union
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    // Input the existing roads
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        unite(a, b);
    }

    // Find the number of connected components
    int components = 0;
    for (int i = 1; i <= n; ++i) {
        if (parent[i] == i) {
            components++;
        }
    }

    // Output the result
    std::cout << components - 1 << std::endl;

    int firstComponent = find(1);

    for (int i = 2; i <= n; ++i) {
        if (find(i) != firstComponent) {
            std::cout << firstComponent << " " << i << std::endl;
            unite(firstComponent, i);
        }
    }

    return 0;
}

