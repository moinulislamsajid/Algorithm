#include <bits/stdc++.h>
using namespace std;

int N = 1000;
                                                                                                                                                                   bool vis[N];
vector<int> v[N];
int parArray[N];
bool ans;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int pr = q.front();
        q.pop();

        for (int child : v[pr])
        {
            if (vis[child] == true && parArray[pr] != child)
            {
                ans = true;
                return; // Break out early if a cycle is found
            }

            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                parArray[child] = pr;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(parArray, -1, sizeof(parArray));
    ans = false;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bfs(i);
        }
    }

    if (ans)
    {
        cout << "Cycle Found" << endl;
    }
    else
    {
        cout << "Cycle Not Found" << endl;
    }
}
