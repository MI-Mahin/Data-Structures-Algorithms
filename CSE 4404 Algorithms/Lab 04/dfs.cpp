#include <iostream>
#include <stack>

using namespace std;

const int MAX_NODES = 100;

void dfs(int graph[MAX_NODES][MAX_NODES], int numNodes, int startNode) {
    bool visited[MAX_NODES] = {false};
    stack<int> st;

    st.push(startNode);

    cout << "DFS Order: ";

    while (!st.empty()) {
        int currentNode = st.top();
        st.pop();

        if (!visited[currentNode]) {
            cout << currentNode << " ";
            visited[currentNode] = true;
        }


        for (int i = numNodes - 1  ; i >= 0; --i) {
            if (graph[currentNode][i] == 1 && !visited[i]) {
                st.push(i);
            }
        }
    }

    cout << endl;
}

int main() {
    int numNodes, startNode;

    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    int graph[MAX_NODES][MAX_NODES];

    cout << "Enter the adjacency matrix (0 for no edge, 1 for an edge):\n";

    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter the starting node for DFS: ";
    cin >> startNode;

    dfs(graph, numNodes, startNode);

    return 0;
}
