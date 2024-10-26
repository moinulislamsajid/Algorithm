#include <bits/stdc++.h>
using namespace std;

int r, c;
vector<vector<bool>> vis;
vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};  // Right, Left, Up, Down

// Valid position checker
bool valid(int x, int y, vector<vector<char>>& play) {
    return x >= 0 && x < r && y >= 0 && y < c && (play[x][y] == '.' || play[x][y] == 'D') && !vis[x][y];
}

// BFS to find the shortest path and mark it with 'X'
void bfs(int stx, int sty, int tx, int ty, vector<vector<char>>& play) {
    queue<pair<int, int>> q;
    vector<vector<pair<int, int>>> parent(r, vector<pair<int, int>>(c, {-1, -1}));
    vis[stx][sty] = true;

    bool found = false;

    // BFS loop
    while (!q.empty()) {
        auto [fir, sec] = q.front();
        q.pop();

        if (fir == tx && sec == ty) {
            found = true;
            break;  // Exit BFS when destination is found
        }

        // Try all movements (right, left, up, down)
        for (auto [dx, dy] : moves) {
            int lx = fir + dx;
            int ly = sec + dy;

            if (valid(lx, ly, play)) {
                q.push({lx, ly});
                vis[lx][ly] = true;
                parent[lx][ly] = {fir, sec};  // Store the parent to reconstruct the path
            }
        }
    }

    if (found) {
        // Backtrack to mark the path from 'D' to 'R' with 'X'
        int cx = tx, cy = ty;
        while (cx != stx || cy != sty) {
            play[cx][cy] = 'X';
            tie(cx, cy) = parent[cx][cy];  // Move to the parent cell
        }
        play[stx][sty] = 'X';  // Mark the start point 'R' as well
    }
}

int main() {
    cin >> r >> c;
    vector<vector<char>> play(r, vector<char>(c));
    vis.resize(r, vector<bool>(c, false));

    int sx = -1, sy = -1, tx = -1, ty = -1;

    // Read the maze
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> play[i][j];
            if (play[i][j] == 'R') {
                sx = i;
                sy = j;
            }
            if (play[i][j] == 'D') {
                tx = i;
                ty = j;
            }
        }
    }

    if (sx == -1 || sy == -1 || tx == -1 || ty == -1) {
        cout << "Invalid maze: start or destination not found" << endl;
        return 0;
    }

    bfs(sx, sy, tx, ty, play);

    // Output the final maze with the path marked
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << play[i][j];
        }
        cout << endl;
    }

    return 0;
}
