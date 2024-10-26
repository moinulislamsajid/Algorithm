#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int num[n];

    for(int i=0; i<n; i++)
    {
        cin>>num[i];
    }

    int sum;
    cin>>sum;

    // create an 2D arrays

    bool dp[n+1][sum+1];

    dp[0][0] = true;

    for(int i=1; i<=sum; i++)
    {
        dp[0][i] = false;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=sum; j++)
        {
            if(num[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-num[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    if(dp[n][sum])
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
