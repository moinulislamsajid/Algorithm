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

        edgeList.push_back(Edge(u,v,c));
    }

    // set all value INT_MAX

    for(int i=0; i<n; i++)
    {
        dis[i] = INT_MAX;
    }

    // set initial source value 0

    dis[0] = 0;

    for(int i=1; i<=n-1; i++)
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

    // print the distance value

    for(int i=0; i<n; i++)
    {

        cout<<i<<"->"<<dis[i]<<endl;
    }

}
