#include <iostream>
#include <vector>

using namespace std;

int m, n;
vector<vector<char>> grid;
vector<vector<bool>> visited;

const int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

bool isValid(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

void DFS(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 8; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY) && !visited[newX][newY] && grid[newX][newY] == '@') {
            DFS(newX, newY);
        }
    }
}

int countOilDeposits() {
    visited.assign(m, vector<bool>(n, false));
    int oilDeposits = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && grid[i][j] == '@') {
                oilDeposits++;
                DFS(i, j);
            }
        }
    }

    return oilDeposits;
}

int main() {
    int gridNum = 1;
    while (true) {
        cin >> m >> n;
        if (m == 0) {
            break;
        }

        grid.assign(m, vector<char>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        int oilDeposits = countOilDeposits();
        cout << "Grid " << gridNum << ": " << oilDeposits << " oil deposits" << endl;
        gridNum++;
    }

    return 0;
}


