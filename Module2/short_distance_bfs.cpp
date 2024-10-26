#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> adjList[N];
bool vis[N];
int level[N];
int prt[N];

void bfs(int src,int des)
{
    queue<pair<int,int>> q;
    q.push({src,des});

    while(!q.empty())
    {
        pair<int,int> parent = q.front();
        q.pop();

        int fNode= parent.first;
        int fDistance= parent.second;

        for(int child : adjList[fNode])
        {
            if(!vis[child])
            {
                q.push({child,fDistance+1});
                vis[child] = true;
                level[child] = level[fNode]+1;
                prt[child] = fNode;
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

    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    memset(prt,-1,sizeof(prt));

    // called the function

    bfs(src,des);

    int x = des;
    int ans = 0;

    while(x!=-1)
    {
        ans++;
        x = prt[x];
    }

    cout<<ans<<endl;
}
