#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<int> adjList[N];
bool vis[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

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

    int src;
    cin>>src;

    // all set initial value

    memset(vis,false,sizeof(vis));

    // called the function

    bfs(src);
}
