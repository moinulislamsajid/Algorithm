#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool vis[N];
int parentArray[N];
bool ans;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while(!q.empty())
    {
        int pr = q.front();
        q.pop();

        for(int child : adjList[pr])
        {
            if(vis[child] == true && parentArray[pr] != child)
            {
                ans = true;
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

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }



    memset(vis,false,sizeof(vis));
    memset(parentArray,-1,sizeof(parentArray));
    ans = false;

    for(int i=0; i<n; i++)
    {
        if(vis[i] == false)
        {
            bfs(i);
        }
    }

    if(ans)
    {
        cout<<"Cycle Found"<<endl;
    }else
    {
        cout<<"Cycle Not Found"<<endl;
    }


}
