#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<int> adjList[N];
bool vis[N];

void dfs(int src)
{
    cout<<src<<" ";
    vis[src] = true;

    for(int child : adjList[src])
    {
        if(!vis[child])
        {
            dfs(child);
        }
    }
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
        adjList[b].push_back(a);
    }

    int cn=0;

    memset(vis,false,sizeof(vis));

    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
            cn++;
        }

    }

    cout<<"Component : "<<cn<<endl;
}
