#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

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
            vis[child] = true;
            dfs(child);
        }
    }
}


int main()
{
    int n,e;
    cout<<"Enter the number of weight and edge : ";
    cin>>n>>e;

    while(e--)
    {
        int a,b;
        cin>>a>>b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    memset(vis,false,sizeof(vis));
    int src;
    cin>>src;

    dfs(src);

    return 0;
}
