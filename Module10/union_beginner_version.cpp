#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];

void DSU_initialation(int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i] = -1;
    }

    parent[1] = 2;
    parent[2] = 3;
    parent[5] = 6;
    parent[6] = 7;
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

void Union(int node1,int node2)
{
    int LeaderA = findLeader(node1);
    int LeaderB = findLeader(node2);
    parent[LeaderA] = LeaderB;
}

int main()
{
    DSU_initialation(8);
    cout<<findLeader(1)<<endl;

    Union(1,6);
    cout<<findLeader(1)<<endl;


}
