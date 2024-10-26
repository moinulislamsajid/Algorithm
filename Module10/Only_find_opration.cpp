#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];

void DSU_initial(int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i] = -1;

    }

    parent[1] = 3;
    parent[2] = 1;
}

int main()
{



}
