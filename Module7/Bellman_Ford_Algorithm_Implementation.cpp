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
    vector<Edge> edList;
    while(e--)
    {
        int u,v,c;
        cin>>u>>v>>c;
        edList.push_back(Edge(u,v,c));
    }

    // initial set all value maximum

    for(int i=0; i<n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[0] =0;

    for(int i = 1; i<= n - 1; i++)
    {
        for(Edge ed : edList)
        {
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;

            // path relax

            if(dis[u] < INT_MAX && dis[u] + c < dis[v])
            {

                dis[v] = dis[u] + c;
            }

        }
    }

    // print the all distance

    for(int i=0; i<n; i++)
    {
         cout<<i<<"->"<<dis[i]<<endl;
    }

}
