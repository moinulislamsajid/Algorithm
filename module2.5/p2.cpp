#include<bits/stdc++.h>
using namespace std;
const int N = 1005;

vector<int> adjList[N];
bool vis[N];
int level[N];
vector<int> v;

void bfs(int src,int lev)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while(!q.empty())
    {
        int prt = q.front();
        q.pop();



        for(int child : adjList[prt])
        {




            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[prt] + 1;

                if(level[child] == lev)
                {
                    v.push_back(child);
                }
            }


        }
    }

    reverse(v.begin(),v.end());
    for(int val : v)
    {
        cout<<val<<" ";
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
    memset(level,-1,sizeof(level));

    // called the function

    int lev;
    cin>>lev;

    bfs(0,lev);
}
