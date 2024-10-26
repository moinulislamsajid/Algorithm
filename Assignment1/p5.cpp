#include<bits/stdc++.h>
using namespace std;

int r,c;
vector<vector<bool>> vis;
vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};


bool Valid(int x, int y, vector<vector<char>>& play)
{
    return x >= 0 && x < r && y >= 0 && y < c && play[x][y] == '.' && !vis[x][y];
}

int bfs(int startX, int startY, vector<vector<char>>& play)
{

    queue<pair<int, int>> q;
    q.push({startX, startY});
    vis[startX][startY] = true;

    int rc = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        rc++;

        for (auto child : v)
        {
            int f = x + child.first;
            int s = y + child.second;

            if (Valid(f,s,play))
            {

                q.push({f,s});
                vis[f][s] = true;
            }
        }
    }

    return rc;
}

int main()
{

    cin >> r >> c;
    vector<vector<char>> play(r, vector<char>(c));


    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> play[i][j];
        }
    }

    vis.assign(r, vector<bool>(c, false));

    vector<int> vn;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (play[i][j] == '.' && !vis[i][j])
            {
                int room = bfs(i, j, play);
                vn.push_back(room);
            }
        }
    }

    if (vn.empty())
    {
        cout << 0 << endl;
    }
    else
    {
        sort(vn.begin(),vn.end());

        for (int si : vn)
        {
            cout<<si<< " ";
        }
        cout << endl;
    }


}

