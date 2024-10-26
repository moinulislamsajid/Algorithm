#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int parent[N];
int level[N];
int sizelevel[N];

void DSU_inital(int n)
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

    int leader = findLeader(parent[node]);
    parent[node] = leader;
    return leader;
}



void union_by_rank(int node1,int node2)
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
            sizelevel[levelA]+=sizelevel[levelB];
        }else
        {
            parent[levelA] = levelB;
            sizelevel[levelB]+=sizelevel[levelA];
        }
}


int main()
{
    DSU_inital(7);

    union_by_rank(1,2);
    union_by_rank(2,3);
    union_by_rank(4,5);
    union_by_rank(5,6);
    union_by_rank(1,4);


    cout<<findLeader(1)<<endl;
    cout<<findLeader(5)<<endl;
}
