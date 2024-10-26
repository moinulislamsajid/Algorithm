#include<bits/stdc++.h>
using namespace std;
vector<int> v[100];
bool vis[100];

void dfs(int src)
{
    cout<<src<<" ";
    vis[src] = true;

    for(int child : v[src])
    {
        if(vis[child] == true)
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
        v[b].push_back(a);
    }

    int src;
    cin>>src;

    memset(vis,false,sizeof(vis));
    // called the function
    dfs(src);
}
