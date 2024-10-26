#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool vis[N];
int edgeCount = 0;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    vector<int> parent(N, -1);

    while (!q.empty())
    {
        int prt = q.front();
        q.pop();

        for (int child : adjList[prt])
        {
            if (!vis[child])
            {
                vis[child] = true;
                q.push(child);
                parent[child] = prt;
            }
            else if (parent[prt] != child)
            {
                edgeCount++;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            bfs(i);
        }
    }

    cout << edgeCount / 2 << endl;

    return 0;
}
