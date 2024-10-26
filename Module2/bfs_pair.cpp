#include<bits/stdc++.h>
using namespace std;

vector<int>v[1000];
bool vis[1000];
//int level[1000];

void bfs(int src,int des)
{
    queue<pair<int,int>>q;
    q.push({src,0});
    vis[src] = true;
    //level[src] = 0;

    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();

        int pr = p.first;
        int le = p.second;

        //cout<<pr<<endl;
        if(pr == des)
        {
            cout<<le<<endl;
        }

        for(int child : v[pr])
        {
            if(vis[child]==false)
            {

                q.push({child,le+1});
                vis[child] = true;
                level[child] = level[pr]+1;
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

        v[a].push_back(b);
        v[b].push_back(a);
    }

    int src;
    cin>>src;

    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));

    bfs(src,3);


}

