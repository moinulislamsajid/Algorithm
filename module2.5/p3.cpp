#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool vis[N];
int cn = 0;
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while(!q.empty())
    {
        int prt = q.front();
        q.pop();


        for(int child : adjList[prt])
        {
            cn++;
        }
    }

    cout<<cn<<endl;
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

    memset(vis,false,sizeof(vis));

    // called the function

    bfs(src);
}
