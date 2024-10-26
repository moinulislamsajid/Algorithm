#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
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

void union_by_size(int node1,int node2)
{
    int leaderA = findLeader(node1);
    int leaderB = findLeader(node2);

    if(sizelevel[leaderA] > sizelevel[leaderB])
    {
        parent[leaderB] = leaderA;
        sizelevel[leaderA]+=sizelevel[leaderB];
    }else
    {
        parent[leaderA] = leaderB;
        sizelevel[leaderB]+=sizelevel[leaderA];
    }
}

int main()
{

    DSU_initial(7);
    union_by_size(1,2);
    union_by_size(2,3);
    union_by_size(4,5);
    union_by_size(5,6);
    union_by_size(1,5);

    cout<<findLeader(1)<<endl;
    cout<<findLeader(4)<<endl;


}
