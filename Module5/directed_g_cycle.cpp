#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adjList[N];
bool vis[N];
bool pathvis[N];
bool cycle;

void dfs(int src)
{
    vis[src] = true;
    pathvis[src] = true;

    for(int child : adjList[src])
    {
        if(pathvis[child] == true)
        {
            cycle = true;
        }

        if(!vis[child])
        {
            dfs(child);
        }
    }

    pathvis[src] = false;
}

int main()
{
    int n,e;
    cin>>n>>e;

    while(e--)
    {
        int a,b;
        cin>>a>>b;

        adjList[a].push_back(b);
    }

    memset(vis,false,sizeof(vis));
    memset(pathvis,false,sizeof(pathvis));

    for(int i=1; i<n; i++)
    {
        if(!vis[i])
        {
            dfs()
        }
    }
}
