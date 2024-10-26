#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool vis[N];
int level[N];
int parentArrays[N];

void shortPath(int src,int des)
{
   queue<pair<int,int>> q;
   q.push({src,des});
   vis[src] = true;
   level[src] = 0;

   while(!q.empty())
   {
       auto prt = q.front();
       int firNode = prt.first;
       int levelNode = prt.second;
       q.pop();

       for(int child : adjList[firNode])
       {
           if(!vis[child])
           {
               q.push({child,levelNode+1});
               vis[child] = true;
               level[child] = level[firNode]+1;
               parentArrays[child] = firNode;
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

    int src,des;
    cin>>src>>des;

    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    memset(parentArrays,-1,sizeof(parentArrays));

    // called the function

    shortPath(src,des);

    int x = des;

    vector<int>v;

    while(x != -1)
    {
        v.push_back(x);
        x = parentArrays[x];
    }

    reverse(v.begin(),v.end());
    for(int val : v)
    {
        cout<<val<<endl;
    }
}
