#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> vis;
int r, c;

vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int x, int y, vector<vector<char>>& play)
{
    return x >= 0 && x < r && y >= 0 && y < c && play[x][y] != '-' && !vis[x][y];
}

bool bfs(int sx, int sy, int tx, int ty, vector<vector<char>>& grid)
{
    queue<pair<int, int>> q;

    q.push({sx, sy});
    vis[sx][sy] = true;

    while (!q.empty())
    {
        pair<int, int> pr = q.front();
        int fir = pr.first;
        int sec = pr.second;
        q.pop();

        if (fir == tx && sec == ty)
        {
            return true;
        }

        for (auto child : v)
        {
            int n = fir + child.first;
            int s = sec + child.second;

            if (valid(n, s, grid))
            {
                q.push({n, s});
                vis[n][s] = true;
            }
        }
    }
    return false;
}

int main()
{

    cin >> r >> c;

    vector<vector<char>> play(r, vector<char>(c));
    vis.resize(r, vector<bool>(c, false));


    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> play[i][j];
        }
    }


    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    if (play[r1][c1] == '-' || play[r2][c2] == '-')
    {
        cout << "NO" << endl;
    }
    else if (bfs(r1, c1, r2, c2, play))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
