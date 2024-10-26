#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool vis[N];
int parentArray[N];
int edgeCount = 0;


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

                if(vis[child] == false)
                {
                    q.push(child);
                    vis[child] = true;
                    parentArray[child] = prt;
                }
                else if(parentArray[prt] != child)
                {
                    edgeCount++;
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





    for(int i=0; i<n; i++)
    {
        if(vis[i] == false)
        {
            bfs(i);
        }
    }


    cout<<edgeCount/2<<endl;

}

