#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;

    int mat[n][n];

    for(int i= 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin>>mat[i][j];
        }
    }

    vector<int> adjList[n];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(mat[i][j] > 0)
            {
                adjList[i].push_back(j);
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        cout<<i<<"-> ";

        for(int child : adjList[i])
        {
            cout<<child<<" ";
        }

        cout<<endl;
    }
}
