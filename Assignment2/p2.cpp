#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<pair<int,int>> adjList[N];
int parent[N];
int levelrank[N];

void DSU_inital(int n)
{

    for(int i=1; i<=n; i++)
    {
        parent[i] = i;
        levelrank[i] = 0;
    }

}

int findLeader(int node)
{
    if (parent[node] != node)
    {
        parent[node] = findLeader(parent[node]);
    }
    return parent[node];
}

void union_by_rank(int node1,int node2)
{

    int levA = findLeader(node1);
    int levB = findLeader(node2);

    if(levA == levB)
    {
        return;
    }

    if(levelrank[levA] > levelrank[levB])
    {
        parent[levB] = levA;
    }
    if(levelrank[levB] > levelrank[levA])
    {
        parent[levA] = levB;
    }
    else
    {
        parent[levB] = levA;
        levelrank[levA]++;
    }

}

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

bool cmp(Edge a,Edge b)
{
    return a.c < b.c;
}



int main()
{

    int n,e;
    cin>>n>>e;
    DSU_inital(n);
    vector<Edge> edList;

    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;

        edList.push_back(Edge(a,b,c));
    }

    sort(edList.begin(),edList.end(),cmp);

    long long int minCost = 0;
    int edge = 0;

    for(Edge ed : edList)
    {
        int first = findLeader(ed.u);
        int second = findLeader(ed.v);

        if(first != second)
        {
            union_by_rank(ed.u,ed.v);
            minCost+=ed.c;
            edge++;
        }
    }

    if(edge == n-1)
    {
        cout<<minCost<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }

}
