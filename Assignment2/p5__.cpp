#include<bits/stdc++.h>
using namespace std;

int r, c;
vector<vector<bool>> vis;
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
vector<vector<pair<int, int>>> parent;

bool valid(int x, int y, vector<vector<char>> &play) {
    return x >= 0 && x < r && y >= 0 && y < c && (play[x][y] == '.' || play[x][y] == 'D') && !vis[x][y];
}

void bfs(int stx, int sty, int tx, int ty, vector<vector<char>> &play) {
    queue<pair<int, int>> q;
    q.push({stx, sty});
    vis[stx][sty] = true;

    bool res = false;
    while (!q.empty()) {
        pair<int, int> prt = q.front();
        int fir = prt.first;
        int sec = prt.second;
        q.pop();

        if (fir == tx && sec == ty) {
           res = true;
            break;
        }

        for (pair<int, int> dir : directions) {
            int lx = fir + dir.first;
            int ly = sec + dir.second;

            if (valid(lx, ly, play)) {
                q.push({lx, ly});
                vis[lx][ly] = true;
                parent[lx][ly] = {fir, sec};
            }
        }
    }


    if (res == true) {
        int cx = tx,cy = ty;
        while (cx != stx||cy != sty) {
            if (play[cx][cy] != 'D')
                play[cx][cy] = 'X';
            pair<int, int> p = parent[cx][cy];
            cx = p.first;
            cy = p.second;
        }
        play[stx][sty] = 'R';
    }
}

int main() {
    cin >> r >> c;

    vector<vector<char>> play(r, vector<char>(c));
    vis.resize(r, vector<bool>(c, false));
    parent.resize(r, vector<pair<int, int>>(c, {-1, -1}));

    int sx = -1, sy = -1, tx = -1, ty = -1;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> play[i][j];
        }
    }

    for(int i = 0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
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

    bfs(sx,sy,tx,ty,play);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << play[i][j];
        }
        cout << endl;
    }


}

