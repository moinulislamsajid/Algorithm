#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> v[N];
bool vis[N];
int parent[N];
bool pathVis[N];
bool ans;

void dfs(int src)
{

    vis[src] = true;
    pathVis[src] = true;
    for(int child : v[src])
    {

        if(pathVis[child])
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

        v[a].push_back(b);

    }

    memset(vis,false,sizeof(vis));
    memset(pathVis,false,sizeof(pathVis));
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
    }else
    {
        cout<<"Cycle Not Found"<<endl;
    }
}
