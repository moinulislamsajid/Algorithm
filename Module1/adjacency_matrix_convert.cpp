// we use adjacency matrix how connection between two nodes

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;

    int adjMatrix[n][n];

    // default set to all index value 0

    memset(adjMatrix,0,sizeof(adjMatrix));

    while(e--)
    {
        int a,b;
        cin>>a>>b;

        adjMatrix[a][b] = 1;
        adjMatrix[b][a] = 1;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<adjMatrix[i][j]<<" ";
        }

        cout<<endl;
    }

    cout<<"NOW time to check connection retain or not : "<<endl;
    cout<<endl;

    int row,col;
    cout<<"Enter row and col : "<<endl;
    cin>>row>>col;

    if(adjMatrix[row][col] == 1)
    {
        cout<<"Connection Found"<<endl;
    }
    else
    {
        cout<<"Connection Not Found"<<endl;
    }
}
