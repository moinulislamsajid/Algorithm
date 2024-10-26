#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];
bool pathvis[N];
bool cycle;

void dfs(int src)
{
    vis[src] = true;
    pathvis[src] = true;

    for(int child : adj[src])
    {
        if(pathvis[child] == true)
        {
            cycle = true;
        }
        if(vis[child] == false)
        {
            dfs(child);
        }
    }

    // when all work are done

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
        adj[a].push_back(b);
    }

    memset(vis,false,sizeof(vis));
    memset(pathvis,false,sizeof(pathvis));
    cycle = false;

    for(int i=0; i<n; i++)
    {
        if(vis[i] == false)
        {
            dfs(i);
        }
    }

    if(cycle)
    {
        cout<<"Cycle Found"<<endl;
    }
    else
    {
        cout<<"Cycle Not Found"<<endl;
    }
}
