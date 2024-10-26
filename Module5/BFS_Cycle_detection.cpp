#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> adj[N];
bool vis[N];
int parentArray[N];
bool cycle;

void bfs(int src)
{
    queue<int> q;
    q.push(src);

    vis[src] = true;

    while(!q.empty())
    {
        int pr = q.front();
        q.pop();

        for(int child : adj[pr])
        {
            if(vis[child] == true && parentArray[pr] != child)
            {

                cycle = true;
                return;

            }
            if(vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                parentArray[child] = pr;
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

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(vis,false,sizeof(vis));
    memset(parentArray,-1,sizeof(parentArray));
    cycle = false;

    for(int i=0; i<n; i++)
    {
        if(vis[i] == false)
        {
            bfs(i);
        }
    }

    if(cycle)
    {
        cout<<"Cycle Found"<<endl;
    }else
    {
        cout<<"Cycle Not Found"<<endl;
    }
}
