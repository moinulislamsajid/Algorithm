#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> adjList[N];
bool vis[N];
int prtA[N];
int level[N];

void bfs(int src,int des)
{

    queue<pair<int,int>> q;
    q.push({src,des});
    vis[src] = true;
    level[src] = 0;

    while(!q.empty())
    {
        pair<int,int> prt = q.front();
        q.pop();

        int fSource = prt.first;
        int fdest = prt.second;


        for(int child : adjList[fSource])
        {
            if(!vis[child])
            {
                q.push({child,fdest+1});
                vis[child] = true;
                level[child] = level[fSource]+1;
                prtA[child] = fSource;
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
    memset(prtA,-1,sizeof(prtA));
    memset(level,-1,sizeof(level));

    // called the method

    bfs(src,des);

    int x = des;

    int ans = 0;

    while(x!=-1)
    {
        ans++;
        x = prtA[x];
    }

    cout<<ans<<endl;

}
