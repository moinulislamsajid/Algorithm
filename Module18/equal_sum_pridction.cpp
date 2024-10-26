#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int s=0;

    int num[n];

    for(int i=0; i<n; i++)
    {
        cin>>num[i];
        s+=num[i];
    }

    if(s%2==0)
    {
        int mid_sum = s/2;
        bool dp[n+1][mid_sum+1];
        dp[0][0] = true;

        for(int i=1; i<=mid_sum; i++)
        {
            dp[0][i] = false;
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=mid_sum; j++)
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

        if(dp[n][mid_sum])
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    else
    {
        cout<<"NO"<<endl;
    }


}
