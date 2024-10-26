#include<bits/stdc++.h>
using namespace std;

vector<int> v[1000];
bool vis[1000];
int level[1000];

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

        cout<<pr<<endl;

        for(int child : v[pr])
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
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int src;
    cin>>src;

    memset(vis,false,sizeof(vis));
    bfs(src);

}
