#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];
bool pathV[N];
bool ans;

void dfs(int src)
{

    vis[src] = true;
    pathV[src] = true;

    for(int child : adj[src])
    {
        if(pathV[child])
        {
            ans = true;
        }
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
        adj[a].push_back(b);
    }

    memset(vis,false,sizeof(vis));
    memset(pathV,false,sizeof(pathV));
    ans = false;

    for(int i = 0; i<n; i++)
    {
        if(vis[i] == false)
        {
            dfs(i);
        }
    }

    if(ans)
    {
        cout<<"Cycle Found"<<endl;
    }else
    {
        cout<<"Cycle Not Found"<<endl;
    }
}
