#include<bits/stdc++.h>
using namespace strd;

vector<int> num[1000];
bool vis[1000];

void bfs(int src)
{
    queue<int> q;
    q.push(src);

    num[src] = true;

    while(!q.empty())
    {
        int pr = q.front();
        q.pop();
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

    // initial the value false

    memset(vis,false,sizeof(vis));

    bfs(src);
}
