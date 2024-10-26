#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n,e;
    cin>>n>>e;

    int num[n][n];

    // to set the number initial 0

    memset(num,0,sizeof(num));

    while(e--)
    {
        int a,b;
        cin>>a>>b;

        num[a][b] = 1;
        num[b][a] = 1;

    }

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cout<<num[i][j]<<" ";
        }


        cout<<endl;
    }

}
