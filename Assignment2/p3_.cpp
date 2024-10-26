#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<bool>> vis;
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int x, int y, vector<vector<char>>& play)
{
    return x >= 0 && x < n && y >= 0 && y < m && play[x][y] == '.' && !vis[x][y];
}

int bfs(int i, int j, vector<vector<char>>& play)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;
    int area = 1; // Start with current cell

    while (!q.empty())
    {
        auto prt = q.front();
        q.pop();

        for (auto& dir : directions)
        {
            int newX = prt.first + dir.first;
            int newY = prt.second + dir.second;

            if (valid(newX, newY, play))
            {
                q.push({newX, newY});
                vis[newX][newY] = true;
                area++; // Increment area for each valid dot found
            }
        }
    }
    return area; // Return the total area of this component
}

int main()
{
    cin >> n >> m;
    vector<vector<char>> play(n, vector<char>(m));
    vis.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> play[i][j];
        }
    }

    int minArea = INT_MAX;
    bool foundComponent = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (play[i][j] == '.' && !vis[i][j])
            {
                foundComponent = true; // Found at least one component
                int area = bfs(i, j, play);
                minArea = min(minArea, area);
            }
        }
    }

    if (foundComponent)
    {
        cout << minArea << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}

