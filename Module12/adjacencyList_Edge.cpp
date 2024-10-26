#include<bits/stdc++.h>
using namespace std;

class Edge
{
public :

    int u,v,c;

    Edge(int u,int v, int c)
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

    vector<pair<int,int>> v[n];

    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;

        v[a].push_back({b,c});
    }

    vector<Edge> ed;

    for(int i = 0; i<n; i++)
    {
        for(pair<int,int> child : v[i])
        {
            int node = child.first;
            int cost = child.second;
            ed.push_back(Edge(i,node,cost));
        }
    }

     for(Edge e : ed)
    {
        cout<<e.u<<" "<<e.v<<" "<<e.c<<endl;
    }

    // print the value


}
