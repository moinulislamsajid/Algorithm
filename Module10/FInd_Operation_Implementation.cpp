#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int parent[N];

void DSU_initial(int n)
{
    for(int i =0; i<n; i++)
    {
        parent[i] = -1;
    }

    parent[1] = 3;
    parent[2] = 1;
}


int findL(int node)
{
    if(parent[node] == -1)
    {
        return node;
    }

    int leader = findL(parent[node]);

    parent[node] = leader;

    return leader;
}

int main()
{

    // called those function

    DSU_initial(4);

    cout<<findL(0)<<endl;
    cout<<findL(1)<<endl;
    cout<<findL(2)<<endl;
    cout<<findL(3)<<endl;
}
