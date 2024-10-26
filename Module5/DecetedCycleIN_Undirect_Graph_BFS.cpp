#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool vis[N];
vector<int> adj[N];
int parentArrays[N];
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


        for(int child : adj[pr])
        {

            if(vis[child] == true && parentArrays[pr] != child)
            {
                ans = true;
            }


            if(vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                parentArrays[child] = pr;
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
    memset(parentArrays,-1,sizeof(parentArrays));
    ans = false;

    for(int i = 0; i<n; i++)
    {
        if(vis[i] == false)
        {

            bfs(i);
        }
    }

    if(ans == true)
    {
        cout<<"Cycle Found"<<endl;
    }else
    {
        cout<<"Cycle Not Found"<<endl;
    }


}
