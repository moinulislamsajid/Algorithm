#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int parent[N];
int sizelevel[N];

void DSU_initial(int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i] = -1;
        sizelevel[i] = 1;
    }
}

int findLeader(int node)
{
    if(parent[node] == -1)
    {
        return node;
    }

    int leader = findLeader(parent[node]);
    parent[node] = leader;
    return leader;
}

void size_by_rank(int node1,int node2)
{

    int leaderA = findLeader(node1);
    int leaderB = findLeader(node2);


    if(sizelevel[leaderA] > sizelevel[leaderB])
    {
        parent[leaderB] = leaderA;
        sizelevel[leaderA]+=sizelevel[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        sizelevel[leaderB]+=sizelevel[leaderA];
    }

}



class Edge
{
public :

    int u,v,c;

    Edge(int u,int v,int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

bool cmp(Edge a,Edge b)
{
    return a.c < b.c;
}

int main()
{
    int n,e;
    cin>>n>>e;
    DSU_initial(n);
    vector<Edge> edgeList;
    int tcost = 0;
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;

        edgeList.push_back(Edge(a,b,c));

    }
    sort(edgeList.begin(),edgeList.end(),cmp);

    for(Edge ed : edgeList)
    {
        int leaderU = findLeader(ed.u);
        int leaderV = findLeader(ed.v);

        if(leaderU == leaderV)
        {
            continue;
        }
        else
        {
            size_by_rank(ed.u,ed.v);
            tcost+=ed.c;

        }
    }

    cout<<tcost<<endl;
}

