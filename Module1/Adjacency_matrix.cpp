#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;

    int adj[n][n];

    // initial 2D array 0 value

    memset(adj,0,sizeof(adj));

    while(e--)
    {
        int a,b;
        cin>>a>>b;

        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            cout<<adj[i][j]<<" ";
        }

        cout<<endl;
    }

    if(adj[0][5] == 1)
    {
        cout<<"Connection Ache"<<endl;
    }
    else
    {

         cout<<"Connection Nai"<<endl;
    }
}
