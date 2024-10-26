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
        if(vis[child] == false)
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

    int src;
    cin>>src;

    memset(vis,false,sizeof(vis));

    // called the function

    dfs(src);
}
