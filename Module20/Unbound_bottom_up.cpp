#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,w;
    int>>n>>w;

    int weight[n],value[n];



    for(int j=0; j<n; j++)
    {
        cin>>value[j];
    }

    for(int i=0; i<n; i++)
    {
        cin>>weight[i];
    }

    int dp[n+1][w+1];

    // initial the value

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=w; j++)
        {
            if(weight[i-1] <=j)
            {
                dp[i][j] = max(value[i-1]+dp[i][j-weight[i-1],dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

}
