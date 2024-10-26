#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int parent[N];
int group[N];
int lsize[N];

void initial_DSU(int n)
{
    for(int i = 0; i<n; i++)
    {
        parent[i] = -1;
        lsize[i] = 1;


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

void DSU_union_by_size(int node1,int node2)
{

    int leaderA = findLeader(node1);
    int leaderB = findLeader(node2);


    if(lsize[leaderA] > lsize[leaderB])
    {
        parent[leaderB] = leaderA;
        lsize[leaderA]+=lsize[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        lsize[leaderB]+=lsize[leaderA];
    }


}

int main()
{
    int n,e;
    cin>>n>>e;

    initial_DSU(n);

    bool cycle = false;

    while(e--)
    {

        int a,b;
        cin>>a>>b

        int leaderA = findLeader(a);
        int leaderB = findLeader(b);

        if(leaderA == leaderB)
        {
            cycle = true;
        }
        else
        {
            DSU_union_by_size(a,b);
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
