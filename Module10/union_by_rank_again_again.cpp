#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int parent[N];
int level[N];
int sizelevel[N];

void DSU_Initial(int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i] = -1;
        level[i] = 0;
        sizelevel[i] = 1;
    }
}

int findLeader(int node)
{
    if(parent[node] == -1)
    {
        return node;
    }

    int leader = parent[node];
    parent[node] = leader;
    return leader;
}

void union_by_rank(int node1,int node2)
{
    int level1 = findLeader(node1);
    int level2 = findLeader(node2);

    if(level1 == level2)
    {
        return;
    }

    else if(level[level1] > level[level2])
    {
        parent[level2] = level1;
        sizelevel[level1]+=sizelevel[level2];
    }
    else
    {
        parent[level1] = level2;
        sizelevel[level2]+=sizelevel[level1];
    }
}

int main()
{
    DSU_Initial(7);

    union_by_rank(1,2);
    union_by_rank(2,3);
    union_by_rank(4,5);
    union_by_rank(5,6);
    union_by_rank(1,5);


    cout<<findLeader(2)<<endl;
    cout<<findLeader(5)<<endl;


}
