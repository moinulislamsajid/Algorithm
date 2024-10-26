#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<int> adjList[N];
bool vis[N];

int dfs(int src)
{
    vis[src] = true;
    int ans = 1;
    for(int child : adjList[src])
    {
        if(!vis[child])
        {
            ans+=dfs(child);
        }

    }

    return ans;
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



    vector<int>v;

    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            int a = dfs(i);

            v.push_back(a);

        }

    }

    sort(v.begin(),v.end());
    for(int val : v)
    {
        cout<<val<<" ";
    }
}
