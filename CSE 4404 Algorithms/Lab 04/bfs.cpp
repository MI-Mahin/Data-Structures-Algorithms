#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

void addEdge(int x, int y)
{
    adj[x][y] = 1;
    adj[y][x] = 1;
}

void bfs(int start)
{
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    q.push(start);

    visited[start] = true;

    int vis;
    while (!q.empty())
    {
        vis = q.front();
        cout << vis << " ";
        q.pop();
        for (int i = 0; i < adj[vis].size(); i++)
        {
            if (adj[vis][i] == 1 && (!visited[i]))
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int v = 10;
    adj = vector<vector<int>>(v, vector<int>(v, 0));

    addEdge(7, 1);
    addEdge(7, 4);
    addEdge(1, 9);
    addEdge(9, 4);
    addEdge(1, 2);
    addEdge(9, 3);
    addEdge(9, 8);
    addEdge(3, 5);
    addEdge(3, 6);
    addEdge(5, 6);
    addEdge(5, 2);
    bfs(1);
    return 0;
}
