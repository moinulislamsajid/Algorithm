#include <bits/stdc++.h>
using namespace std;

int const N = 1e3+5;
bool vis[N][N];
int dis[N][N];
vector<pair<int, int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};
map<pair<int, int>, pair<int, int>> parent;


int rows, cols;
bool destinationFound;
char maze[MAX_SIZE][MAX_SIZE];

bool isValidMove(int x, int y)
{
    return (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] != '#');
}

void bfs(int startX, int startY)
{
    queue<pair<int, int>> bfsQueue;
    bfsQueue.push({startX, startY});
    visited[startX][startY] = true;
    distanceGrid[startX][startY] = 0;

    while (!bfsQueue.empty())
    {
        pair<int, int> current = bfsQueue.front();
        int curX = current.first, curY = current.second;

        if (maze[curX][curY] == 'D')
        {
            destinationFound = true;
        }
        bfsQueue.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextX = curX + directions[i].first;
            int nextY = curY + directions[i].second;

            if (isValidMove(nextX, nextY) && !visited[nextX][nextY])
            {
                bfsQueue.push({nextX, nextY});
                visited[nextX][nextY] = true;
                distanceGrid[nextX][nextY] = distanceGrid[curX][curY] + 1;
                parent[ {nextX, nextY}] = {curX, curY};
            }
        }
    }
}

int main()
{
    int startX, startY, destX, destY;
    cin >> rows >> cols;
    destinationFound = false;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'R')
            {
                startX = i;
                startY = j;
            }
            if (maze[i][j] == 'D')
            {
                destX = i;
                destY = j;
            }
        }
    }

    memset(visited, false, sizeof(visited));
    memset(distanceGrid, -1, sizeof(distanceGrid));

    bfs(startX, startY);

    if (!destinationFound)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << maze[i][j];
            }
            cout << endl;
        }
        return 0;
    }

    int curX = parent[ {destX, destY}].first, curY = parent[ {destX, destY}].second;
    while (maze[curX][curY] != 'R')
    {
        maze[curX][curY] = 'X';
        int nextX = parent[ {curX, curY}].first;
        curY = parent[ {curX, curY}].second;
        curX = nextX;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << maze[i][j];
        }
        cout << endl;
    }

    return 0;
}
