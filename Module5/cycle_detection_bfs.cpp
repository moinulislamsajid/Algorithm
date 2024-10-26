#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<int> adjList[N];
int parentArrays[N];
bool vis[N];
bool flag;


void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src] = true;

    while(!q.empty())
    {
        int prt = q.front();
        q.pop();

        for(int child : adjList[prt])
        {
            if(vis[child] == true && parentArrays[prt] != child)
            {
                flag = true;
            }
            if(vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                parentArrays[child] = prt;
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
    memset(parentArrays,-1,sizeof(parentArrays));
    flag = false;


    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            bfs(i);
        }
    }


    if(flag==true)
    {
        cout<<"Cycle Found"<<endl;
    }
    else
    {
        cout<<"Cycle Not Found"<<endl;
    }
}
