#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin>>n;
    int num[n];
    int sum=0;

    for(int i=0; i<n; i++)
    {
        cin>>num[i];
        sum+=num[i];
    }

    int ts;
    cin>>ts;

    int diff = (ts+sum)/2;

    if(diff%2==0)
    {
        int dp[n+1][diff];
        dp[0][0] = 1;

        for(int i=1; i<=diff; i++)
        {
            dp[0][i] = 0;
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=diff; j++)
            {
                if(num[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-num[i-1]]+dp[i-1][j];
                }
                else
                {

                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        cout<<dp[n][diff]<<endl;

    }

}
