#include <bits/stdc++.h>
using namespace std;

// Directions for moving left, right, up, down
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

// Function to check if a position is valid (within bounds and not a wall)
bool isValid(int x, int y, int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    return x >= 0 && x < r && y >= 0 && y < c && grid[x][y] != '#' && !visited[x][y];
}

// BFS function to determine if we can go from A to B
bool bfs(int startX, int startY, int targetX, int targetY, int r, int c, vector<vector<char>>& grid) {
    // Queue to store coordinates for BFS
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(r, vector<bool>(c, false));

    // Starting point (room 'A')
    q.push({startX, startY});
    visited[startX][startY] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // If we reach room 'B', return true
        if (x == targetX && y == targetY) {
            return true;
        }

        // Explore adjacent cells (left, right, up, down)
        for (auto dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;


            // Check if the new position is valid
            if (isValid(newX, newY, r, c, grid, visited)) {
                q.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
    }

    // If we finish the BFS and haven't found room 'B', return false
    return false;
}

int main() {
    int r, c;
    cin >> r >> c;

    // Grid to store the map
    vector<vector<char>> grid(r, vector<char>(c));

    // Variables to store the coordinates of rooms A and B
    int startX = -1, startY = -1, targetX = -1, targetY = -1;

    // Read the grid
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                startX = i;
                startY = j;
            } else if (grid[i][j] == 'B') {
                targetX = i;
                targetY = j;
            }
        }
    }

    // Perform BFS from room 'A' to room 'B'
    if (bfs(startX, startY, targetX, targetY, r, c, grid)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
