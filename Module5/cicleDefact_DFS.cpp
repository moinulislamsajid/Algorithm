#include<bits/stdc++.h>
using namespace std;

const long long int N = 1e5+5;
bool vis[N];
vector<int> v[N];
int parentA[N];
bool ans;

void dfs(int src)
{
    vis[src] = true;

    for(auto child : v[src])
    {
        if(vis[child] == true && parentA[src])
        {

            ans = true;


        }


       if(!vis[child])
        {
            dfs(child);
            parentA[child] = src;
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

    memset(vis,false,sizeof(vis));
    memset(parentA,-1,sizeof(parentA));
    ans = false;

    for(int i= 0; i<n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
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
