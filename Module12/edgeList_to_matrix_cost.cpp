#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;

    int mat[n][n];

    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;

        mat[a][b] = c;
        mat[b][a] = c;
    }

    for(int i = 0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<mat[i][j]<<" ";
        }

        cout<<endl;
    }
}
