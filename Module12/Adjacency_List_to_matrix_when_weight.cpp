#include<bits/stdc++.h>
using namespace std;

void convert(int n,vector<pair<int,int>> adj[])
{

    int matrix[n][n];
    for(int i = 0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            matrix[i][j] = -1;
            if(i==j)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // now logic for convert implementation

    for(int i=0; i<n; i++)
    {
        for(pair<int,int> child : adj[i])
        {
            int node =  child.first;
            int cost = child.second;

            matrix[i][node] = cost;
        }
    }

    // now print the matrix

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cout<<matrix[i][j]<<" ";
        }

        cout<<endl;
    }

}



int main()
{

    int n,e;
    cin>>n>>e;
    vector<pair<int,int>> adlist[n];

    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;

        adlist[a].push_back({b,c});
    }

    // called the function

    convert(n,adlist);

}
