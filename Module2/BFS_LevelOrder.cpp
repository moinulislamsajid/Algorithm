#include<bits/stdc++.h>
using namespace std;

vector<int> num[1000];
int level[1000];
bool vis[1000];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while(!q.empty())
    {
        int pr = q.front();
        q.pop();
       // cout<<pr<<" ";
        for(int child : num[pr])
        {
            if(vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[pr] + 1;
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

        num[a].push_back(b);
        num[b].push_back(a);
    }

    int src;
    cin>>src;

    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));

    bfs(src);

    for(int i=0; i<n; i++)
    {

        cout<<i<<" "<<level[i]<<endl;

    }



}
