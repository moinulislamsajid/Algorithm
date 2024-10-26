#include<bits/stdc++.h>
using namespace std;


vector<int> v[100];
bool vis[1000];


void bfs(int src)
{

    cout<<src<<" ";
    vis[src] = true;

    for(int child : v[src])
    {
        if(vis[child] == false)
        {
            bfs(child);
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
    bfs(src);


}
