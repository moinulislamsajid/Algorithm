#include<bits/stdc++.h>
using namespace std;

vector<int> num[100];
bool vis[100];
int level[100];
int prt[100];

// create a variable

void bfs(int src,int des)
{
    queue<pair<int,int>> q;
    q.push({src,des});
    vis[src] = true;

    while(!q.empty())
    {
        pair<int,int> pr = q.front();
        q.pop();

        int fir = pr.first;
        int lev = pr.second;

        for(int child : num[fir])
        {
            if(vis[child] == false)
            {
                q.push({child,lev+1});
                vis[child] = true;
                level[child] = level[fir]+1;
                prt[child] = fir;

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

    int src,des;
    cin>>src>>des;

    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    memset(prt,-1,sizeof(prt));

    // called the method

    bfs(src,des);

    int x = des;
    vector<int>vn;
    while(x!=-1)
    {

        vn.push_back(x);
        x = prt[x];


    }

    // reverse the vector

    reverse(vn.begin(),vn.end());

    for(int i : vn)
    {
        cout<<i<<" ";
    }
}
