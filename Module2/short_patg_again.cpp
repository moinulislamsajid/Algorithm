#include<bits/stdc++.h>
using namespace std;

vector<int>num[100];
bool vis[100];
int level[100];
int prt[100];

void bfs(int src,int des)
{
    queue<pair<int,int>>q;

    q.push({src,des});
    vis[src] = true;

    while(!q.empty())
    {
        pair<int,int> p = q.front();
        int fp = p.first;
        int levl = p.second;

        for(int child : num[fp])
        {
            if(vis[child] == false)
            {
                q.push({child,levl+1});
                vis[child] = true;
                level[child] = level[fp]+1;
                prt[child] = fp;
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

    int src,des;
    cin>>src>>des;

    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    memset(prt,-1,sizeof(prt));

    bfs(src,des);

    int x = des;

    vector<int> v;

    while(x!=-1)
    {
        v.push_back(x);
        x = prt[x];
    }

    reverse(v.begin(),v.end());
    for(int h : v)
    {
        cout<<h<<" ";
    }
}
