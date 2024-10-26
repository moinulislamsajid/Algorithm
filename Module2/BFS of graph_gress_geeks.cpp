#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+5;
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
        int prt = q.front();
        q.pop();

        cout<<prt<<" ";
        for(int child : adjList[prt])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = prt;
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
    }

    int src;
    cin>>src;

    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));

    // called the function

    bfs(src);

}
