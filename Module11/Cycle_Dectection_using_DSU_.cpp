#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int sizelevel[N];
int parent[N];

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

void rank_by_size(int node1,int node2)
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

    int n,e;
    cin>>n>>e;

    DSU_initial(n);

    bool cycle = false;

    while(e--)
    {
        int a,b;
        cin>>a>>b;

        int leadA = findLeader(a);
        int leadB = findLeader(b);

        // now check the condition

        if(leadA == leadB)
        {
            cycle = true;
        }
        else
        {
            rank_by_size(a,b);
        }
    }

    if(cycle)
    {
        cout<<"Cycle Found"<<endl;
    }else
    {
        cout<<"Cycle Not Found"<<endl;
    }


}
