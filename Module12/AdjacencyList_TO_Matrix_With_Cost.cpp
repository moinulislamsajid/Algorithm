#include<bits/stdc++.h>
using namespace std;

void convert(int n,vector<pair<int,int>> adjList[])
{


    int mat[n][n];

    for(int i=0; i<n; i++)
    {

        for(int j=0; j<n; j++)
        {
            mat[i][j] = -1;
            if(i==j)
            {
                mat[i][j] = 0;
            }
        }
    }

    for(int i = 0; i<n; i++)
    {
        for(pair<int,int> child : adjList[i])
        {
            int node = child.first;
            int cost = child.second;

            mat[i][node] = cost;
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>> adjList[n];
    while(e--)
    {

        int a,b,c;
        cin>>a>>b>>c;

        adjList[a].push_back({b,c});
    }

    // called the method

    convert(n,adjList);
}
