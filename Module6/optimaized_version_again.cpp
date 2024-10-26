#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<pair<int,int>> adjList[N];
int dis[N];

class cmp
{
public:

    bool operator ()(pair<int,int> a,pair)
    {
        return a.second > b.second;
    }
};


void dijakra(int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>,cmp> pq;
    pq.push({src,0});
    dis[src] = 0;

    while(!q.empty())
    {
        pair<int,int> prt = pq.top();
        pq.pop();

        int PrtNode = prt.first;
        int Prtcost = prt.second;

        for(pair<int,int> child : adjList[PrtNode])
        {

            int childNode = child.first;
            int childCost = child.second;

            if(Prtcost + childCost < dis[childNode])
            {

                dis[childNode] = Prtcost + childCost;
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

    for(int i=0; i<n; i++)
    {
        dis[i] = INT_MAX;
    }

    int src;
    cin>>src;

    // to called the function

    dijakra(src);

    // print the value

    for(int i=0; i<n; i++)
    {
        cout<<i<<"-> "<<dis[i]<<endl;
    }

}
