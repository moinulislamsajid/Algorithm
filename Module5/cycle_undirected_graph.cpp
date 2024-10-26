#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adjList[N];
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
        int prt = q.front();
        q.pop();

        for(int child : adjList[prt])
        {
            if(vis[child] == true && parentArray[prt] != child)
            {
                cycle = true;
            }

            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                parentArray[child] = prt;
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

    memset(vis,false,sizeof(vis));
    memset(parentArray,-1,sizeof(parentArray));
    cycle = false;

    for(int i=1; i<n; i++)
    {
        if(!vis[i])
        {
            bfs(i);
        }
    }

    if(cycle)
    {
        cout<<"Cycle Found"<<endl;
    }
    else
    {
        cout<<"Cycle Not Found"<<endl;
    }

}
