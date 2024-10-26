#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dis[N];
vector<pair<int,int>> adjList[N];

class cmd
{
public :

    bool operator ()(pair<int,int> a,pair<int,int> b)
    {

        return a.second > b.second;
    }
};


void optimizedVersion(int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmd> pq;

    pq.push({src,0});
    dis[src] = 0;

    while(!pq.empty())
    {
        pair<int,int> prt = pq.top();
        int partNode = prt.first;
        int prtCost = prt.second;
        pq.pop();

        for(auto child : adjList[partNode])
        {
            int childNode = child.first;
            int childCost = child.second;

            if(prtCost + childCost < dis[childNode])
            {
                dis[childNode] = prtCost + childCost;
                pq.push({childNode,dis[childNode]});
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

    optimizedVersion(src);

    // print the cost

    for(int i=0; i<n; i++)
    {
        cout<<i<<"->"<<dis[i]<<endl;
    }

}
