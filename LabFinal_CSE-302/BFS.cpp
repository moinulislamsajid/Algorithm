#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

vector<int> adjList[N];
bool vis[N];
int level[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while(!q.empty())
    {
        int prt  = q.front();
        q.pop();

        cout<<prt<<" ";

        for(int child : adjList[prt])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[prt]+1;
            }
        }
    }
}

int main()
{
    int n,e;
    cout<<"\nEnter the number of nodes and edges : ";
    cin>>n>>e;

    while(e--)
    {
        int a,b;
        cin>>a>>b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    int src;
    cin>>src;

    memset(vis,false,sizeof(vis));

    bfs(src);
}
