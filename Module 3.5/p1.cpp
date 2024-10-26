#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<int> adjList[N];
bool vis[N];
int cn = 0;
void dfs(int src)
{

    cn++;
    vis[src] = true;

    for(int child : adjList[src])
    {


        if(!vis[child])
        {
            dfs(child);


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

    int s;
    cin>>s;

    memset(vis,false,sizeof(vis));

    // called the function
    dfs(s);
  cout<<cn<<endl;

}
