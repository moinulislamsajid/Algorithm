#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<pair<int,int>> adjList[N];
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

        int parentNode = prt.first;
        int parentCost = prt.second;

        for(pair<int,int> child : adjList[parentNode])
        {
            int childNode = child.first;
            int childCost = child.second;

            if(parentCost + childCost < dis[childNode])
            {
                dis[childNode] = parentCost + childCost;
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

    // set all maximum

    for(int i=0; i<n; i++)
    {
        dis[i] = INT_MAX;
    }

    int src;
    cin>>src;

    //  called the function


    dijkstra(src);

    // print the distance

    for(int i=0; i<n; i++)
    {
        cout<<i<<"-> "<<dis[i]<<endl;
    }
}
