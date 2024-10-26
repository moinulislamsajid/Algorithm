#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int weight[n];

    for(int i=0; i<n; i++)
    {
        cin>>weight[i];
    }

    int ts;
    cin>>ts;

    int dp[n+1][ts+1];
    dp[0][0] = 0;

    for(int i=1; i<=ts; i++)
    {
        dp[0][i] = INT_MAX - 1;;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=ts; j++)
        {
            if(weight[i-1] <= j)
            {
                dp[i][j] = min(dp[i][j-weight[i-1]]+1,dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<dp[n][ts]<<endl;
}
