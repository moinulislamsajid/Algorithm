#include<bits/stdc++.h>
using namespace std;

class Edge
{
public :

    int u,v,c;


    // create a constructor to initial the value

    Edge(int u,int v,int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

const int N = 1e5 + 5;

int dis[N];

int main()
{
    int n,e;
    cin>>n>>e;
    vector<Edge> edgeList;
    while(e--)
    {
        int u,v,c;
        cin>>u>>v>>c;

        // directed graph

        edgeList.push_back(Edge(u,v,c));
    }

    // set all value infinity

    for(int i = 0; i<n; i++)
    {
        dis[i] = INT_MAX;
    }

    // set the source value 0

    dis[0] = 0;

    for(int i = 1; i<=n-1; i++)
    {
        for(Edge ed : edgeList)
        {
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;

            if(dis[u] < INT_MAX && dis[u] + c < dis[v])
            {

                dis[v] = dis[u] + c;
            }
        }
    }

    bool circle = false;

    for(Edge ed : edgeList)
    {
        int u = ed.u;
        int v = ed.v;
        int c = ed.c;

        if(dis[u] < INT_MAX && dis[u] + c < dis[v])
        {
            circle = true;
            break;
        }
    }

    if(circle)
    {
        cout<<"Cycle Found Can not find Right Answer"<<endl;
    }else
    {
        for(int i = 0; i<n; i++)
        {
            cout<<i<<"->"<<dis[i]<<endl;
        }
    }

}
