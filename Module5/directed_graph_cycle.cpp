#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

vector<int> adjList[N];
bool vis[N];
bool pathvis[N];
bool ans;

void dfs(int src)
{
    vis[src] = true;
    pathvis[src] = true;

    for(int child : adjList[src])
    {
        if(pathvis[child] == true)
        {
            ans = true;
        }
        if(vis[child] == false)
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

        adjList[a].push_back(b); // directed graph
    }

    memset(vis,false,sizeof(vis));
    memset(pathvis,false,sizeof(pathvis));
    ans = false;


    for(int i=0; i<n; i++)
    {
        if(vis[i] == false)
        {
            dfs(i);
        }
    }

    if(ans)
    {
        cout<<"Cycle Found"<<endl;
    }
    else
    {
        cout<<"Cycle Not Found"<<endl;
    }
}
