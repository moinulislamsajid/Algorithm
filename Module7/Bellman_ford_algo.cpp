#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int dis[N];
class Edge
{
public:

    int u,v,c;

    Edge(int u,int v,int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;

    }
};


int main()
{
    int n,e;
    cin>>n>>e;

    vector<Edge> v;

    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;

        v.push_back(Edge(a,b,c));


    }

    // initial the value

    for(int i=0; i<n; i++)
    {
        dis[i] = INT_MAX;
    }

    dis[0] = 0;

    for(int i=1; i<=n-1; i++)
    {
        for(Edge ed : v)
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

    // print the distance arrays

    for(int i=0; i<n; i++)
    {
        cout<<i<<"->"<<dis[i]<<endl;
    }
}
