#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
vector<int> adjList[N];
bool vis[N];

void dfs(int src)
{
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

    memset(vis,false,sizeof(vis));
    int cn = 0;

    for(int i=0; i<n; i++)
    {
        if(vis[i] == false)
        {

            dfs(i);
            cn++;
        }
    }

    cout<<cn<<endl;
}
