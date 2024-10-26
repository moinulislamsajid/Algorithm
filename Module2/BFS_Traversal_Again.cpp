#include<bits/stdc++.h>
using namespace std;

vector<int> num[1000];
bool vis[1000];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while(!q.empty())
    {
        int pr = q.front();
        q.pop();

        cout<<pr<<endl;
        for(int child : num[pr])
        {
            if(vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
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


    int src;
    cin>>src;
    memset(vis,false,sizeof(vis));
    bfs(src);


}
