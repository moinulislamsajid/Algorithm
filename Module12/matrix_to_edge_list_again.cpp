#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;

    int mat[n][n];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>mat[i][j];
        }
    }

    vector<pair<int,int>> edge;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(mat[i][j] == 1 && i!=j)
            {
                edge.push_back({i,j});
            }
        }
    }


    for(pair<int,int> child : edge)
    {
        cout<<child.first<<" "<<child.second;
    }


}
