#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<pair<int,int>> adjList[N];
int parent[N];
int levelrank[N];
int reNode = 0;

void DSU_inital(int n)
{

    for(int i=0; i<n; i++)
    {
        parent[i] = -1;
        levelrank[i] = 0;
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
   }else
   {
       levelrank[levB] = levA;
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
    return a.c<b.c;
}



int main()
{

    int n,e;
    cin>>n>>e;
    DSU_inital(n);
    vector<Edge> edList;

    if(n == 0 || e == 0)
    {
       cout<<"Not Possible"<<endl;
        return 0;
    }

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

        if(first == second)
        {
            continue;

        }else if(first != second)
        {
            union_by_rank(ed.u,ed.v);
            minCost+=ed.c;
            edge++;

        }else
        {
            reNode++;
        }
    }

    if(edge == n-1)
    {
        cout<<reNode<<" "<<minCost<<endl;

    }
    else
    {
        cout<<"Not Possible"<<endl;
    }

}
