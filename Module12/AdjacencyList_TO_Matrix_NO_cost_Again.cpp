#include<bits/stdc++.h>
using namespace std;

void convert(int n,vector<int> adjList[])
{
    int mat[n][n];

    memset(mat,0,sizeof(mat));

    for(int i=0; i<n; i++)
    {
        for(int child : adjList[i])
        {
            mat[i][child] = 1;
        }
    }

    // now print the value

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
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

    vector<int> adjList[n];

    while(e--)
    {
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    // called the function

    convert(n,adjList);


}
