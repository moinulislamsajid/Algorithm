#include<bits/stdc++.h>
using namespace std;

vector<int> num[1000];
bool vis[1000];

void dfs(int src)
{
    cout<<src<<" ";
    vis[src] = true;

    for(int child : num[src])
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

        num[a].push_back(b);
        num[b].push_back(a);
    }

    int src;
    cin>>src;

    memset(vis,false,sizeof(vis));

    dfs(src);
}
