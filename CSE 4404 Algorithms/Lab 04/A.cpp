#include <iostream>

void dfs(int x, int y, int n, int m, char building_map[][1000]) {
    if (x < 0 || x >= n || y < 0 || y >= m || building_map[x][y] == '#') {
        return;
    }

    building_map[x][y] = '#';  // Mark the current floor square as visited

    // Right, Down, Left, Up
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    for (int i = 0; i < 4; ++i) {
        dfs(x + dx[i], y + dy[i], n, m, building_map);
    }
}

int count_rooms(int n, int m, char building_map[][1000]) {
    int room_count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (building_map[i][j] == '.') {
                room_count += 1;
                dfs(i, j, n, m, building_map);
            }
        }
    }

    return room_count;
}

int main() {
    // Input
    int n, m;
    std::cin >> n >> m;

    char building_map[1000][1000];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> building_map[i][j];
        }
    }

    // Output
    int result = count_rooms(n, m, building_map);
    std::cout << result << std::endl;

    return 0;
}

