#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int>adjList[N];
bool vis[N];
int parentArray[N];
bool cycle;

void dfs(int src)
{

    vis[src] = true;

    for(int child : adjList[src])
    {
        if(vis[child] == true && child  != parentArray[src])
        {
            cycle = true;
        }
        if(!vis[child])
        {
           parentArray[child] = src;
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

    memset(vis,false,sizeof(false));
    memset(parentArray,-1,sizeof(parentArray));
    cycle = false;

    for(int i=1; i<n; i++)
    {
        if(!vis[i])
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
