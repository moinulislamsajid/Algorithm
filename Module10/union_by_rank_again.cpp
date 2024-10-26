#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int lsize[N];
int level[N];

void initial_DSU(int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i] = -1;
        lsize[i] = 1;
        level[i] = 0;

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

void rank_by_size(int node1,int node2)
{
    int levelA = findLeader(node1);
    int levelB = findLeader(node2);

    if(levelA == levelB)
    {
        return;
    }
     else if(level[levelA] > level[levelB])
    {
        parent[levelB] = levelA;
        lsize[levelA]+=lsize[levelB];
    }
    else
    {
        parent[levelA]  = levelB;
        lsize[levelB]+=lsize[levelA];
    }
}

int main()
{

    initial_DSU(7);  // Initialize DSU for 7 elements (0 to 6)

    // Union operations
    rank_by_size(1, 2);
    rank_by_size(1, 2);  // This union is redundant but will work fine
    rank_by_size(2, 3);
    rank_by_size(4, 5);
    rank_by_size(5, 6);
    rank_by_size(1, 4);

    // Find operations
    cout << findLeader(1) << endl;
    cout << findLeader(4) << endl;

}
