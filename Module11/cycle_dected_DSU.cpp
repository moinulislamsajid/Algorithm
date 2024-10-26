#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int parent[N];
int sizelevel[N];
int group[N];

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
    parent[leader] = leader;
    return leader;
}

void size_by_group_DUS(int node1,int node2)
{

    int leaderA = findLeader(node1);
    int leaderB = findLeader(node2);


    if(group[leaderA] > group[leaderB])
    {
        parent[leaderB] = parent[leaderA];
        sizelevel[leaderA]+=sizelevel[leaderB];
    }
    else
    {
        parent[leaderA] = parent[leaderB];
        sizelevel[leaderB]+=sizelevel[leaderA];
    }


}


int main()
{
    int n,e;
    cin>>n>>e;

    DSU_initial(n);
    bool cycle = false;

    while(e--)
    {
        int a,b;
        cin>>a>>b;

        int LeaderA = findLeader(a);
        int LeaderB = findLeader(b);

        if(LeaderA == LeaderB)
        {
            cycle = true;
        }else
        {
            size_by_group_DUS(a,b);
        }
    }


    if(cycle)
    {
        cout<<"Cycle Found"<<endl;
    }
    else
    {
        cout<<"Cycle Not Found"<<endl;
    }
}
