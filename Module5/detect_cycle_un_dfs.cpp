#include<bits/stdc++.h>
using namespace std;
const int N = 1005;

vector<int> adjList[N];
bool vis[N];
int parentArrays[N];
bool ans;
void dfs(int src)
{
    vis[src] = true;

    for(int child : adjList[src])
    {
        if(vis[child] == true &&  child != parentArrays[src])
        {
            ans = true;
        }

        if(vis[child] == false)
        {
            parentArrays[child] = src;
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
    memset(parentArrays,-1,sizeof(parentArrays));
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
