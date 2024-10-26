#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int parent[N];
int size_Of[N];

void Initial_DSU(int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i] = -1;
        size_Of[i] = 1;
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
    int LeaderA = findLeader(node1);
    int LeaderB = findLeader(node2);

    if(size_Of[LeaderA] > size_Of[LeaderB])
    {
        parent[LeaderB] = LeaderA;
        size_Of[LeaderA]+=size_Of[LeaderB];
    }else
    {
        parent[LeaderA] = LeaderB;
        size_Of[LeaderB]+=size_Of[LeaderA];
    }
}


int main()
{
    Initial_DSU(7);

    union_by_size(1,2);
    union_by_size(2,3);
    union_by_size(4,5);
    union_by_size(5,6);
    union_by_size(1,4);

    cout<<findLeader(1)<<endl;
    cout<<findLeader(4)<<endl;
}
