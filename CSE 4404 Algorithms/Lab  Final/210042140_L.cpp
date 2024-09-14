//ID- 210042140//
// Name- Mahin //
// ----------- //

//Topological Sorting



#include <iostream>
#include <vector>
#include <queue>

bool topological_sort(int n, int m, std::vector<std::pair<int, int>>& edges) {
    std::vector<int> in_degree(n + 1, 0);
    std::vector<std::vector<int>> graph(n + 1);
    std::queue<int> q;
    std::vector<int> order;

    for (auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
        in_degree[edge.second]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int job = q.front();
        q.pop();
        order.push_back(job);

        for (int dependent_job : graph[job]) {
            --in_degree[dependent_job];
            if (in_degree[dependent_job] == 0) {
                q.push(dependent_job);
            }
        }
    }

    if (order.size() == n) {
        for (int job : order) {
            std::cout << job << " ";
        }
        std::cout << std::endl;
        return true;
    } else {
        std::cout << "Sandro fails." << std::endl;
        return false;
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> edges[i].first >> edges[i].second;
    }

    topological_sort(n, m, edges);
    return 0;
}

