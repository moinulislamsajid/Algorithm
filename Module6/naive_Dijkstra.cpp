#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<pair<int,int>> adjList[N];
int dis[N];

void dijakra(int src)
{
    queue<pair<int,int>> q;
    q.push({src,0});
    dis[src] = 0;

    while(!q.empty())
    {
        auto prt = q.front();
        int prtNode = prt.first;
        int prtCost = prt.second;
        q.pop();

        for(auto child : adjList[prtNode])
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

        adjList[a].push_back({b,c});
        adjList[b].push_back({a,c});
    }

    int src;
    cin>>src;

    // initial the value

    for(int i=0; i<n; i++)
    {
        dis[i] = INT_MAX;
    }

    // called the function

    dijakra(src);

    // print the cost

    for(int i=0; i<n; i++)
    {
        cout<<i<<"->"<<dis[i]<<endl;
    }
}
