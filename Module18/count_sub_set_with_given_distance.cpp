#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin>>n;
    int sum = 0;
    int num[n];

    for(int i=0; i<n; i++)
    {
        cin>>num[i];
        sum+=num[i];
    }

    int dis;
    cin>>dis;

    int fsum = (dis+sum) /2;

    int dp[n+1][fsum+1];

    dp[0][0] = 1;

    for(int i=1; i<=fsum; i++)
    {
        dp[0][i] = 0;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=fsum; j++)
        {
            if(num[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-num[i-1]] + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    /*for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=fsum; j++)
        {
            cout<<dp[i][j]<<" ";
        }

        cout<<endl;
    }*/

    //cout<<endl;

    cout<<dp[n][fsum]<<endl;


}
