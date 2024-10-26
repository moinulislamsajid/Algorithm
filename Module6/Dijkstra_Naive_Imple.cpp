#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<pair<int,int>> adj[N];
int dis[N];

void dijkstra(int src)
{
    queue<pair<int,int>> q;
    q.push({src,0});
    dis[src] = 0;

    while(!q.empty())
    {
        pair<int,int> prt = q.front();
        q.pop();

        int prtNode = prt.first;
        int prtCost = prt.second;

        for(pair<int,int> child : adj[prtNode])
        {
            int childNode = child.first;
            int childCost = child.second;

            if(prtCost + childCost < dis[childNode])
            {
                dis[childNode] = prtCost + childCost;
                q.push({childNode,dis[childNode]});
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
        int a,b,c;
        cin>>a>>b>>c;

        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    // set all value initial maximum

    for(int i =0; i<n; i++)
    {
        dis[i] = INT_MAX;
    }

    int src;
    cin>>src;

    // called the function

    dijkstra(src);

    // now print the all cost

    for(int i = 0; i<n; i++)
    {
        cout<<i<<"->"<<dis[i]<<endl;
    }
}
