#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<int> adjList[N];
bool vis[N];

void bfs(int src,int des)
{

    queue<pair<int,int>> q;
    q.push({src,0});
    vis[src] = 0;

    while(!q.empty())
    {
        pair<int,int> prt = q.front();
        q.pop();

        int prtLev = prt.first;
        int level = prt.second;

        if(prtLev == des)
        {
            cout<<level<<endl;
        }

        for(int child : adjList[prtLev])
        {
            if(!vis[child])
            {
                q.push({child,level+1});
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

    int src,des;
    cin>>src>>des;

    memset(vis,false,sizeof(vis));

    // called the function

    bfs(src,des);
}
