#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<int> adjList[N];
bool vis[N];
int level[N];
int parent[N];

void bfs(int src,int des)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while(!q.empty())
    {
        int prt = q.front();
        q.pop();

        for(int child : adjList[prt])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[prt] + 1;
                parent[child] = prt;
            }
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

    int src,des;
    cin>>src>>des;

    // set up all initial value

    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));

    // called the function

    bfs(src,des);

    // now logic for

    int x = des;

    vector<int> v;

    while(x != -1)
    {
        v.push_back(x);
        x = parent[x];
    }

    reverse(v.begin(),v.end());
    for(int value : v)
    {
        cout<<value<<" ";
    }
}
