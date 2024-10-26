#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s;
    cin>>s;

    int num[s];

    for(int i=0; i<s; i++)
    {
        cin>>num[i];
    }

    int sum;
    cin>>sum;

    bool dp[s+1][sum+1];

    // set the 0,0 index

    dp[0][0] = true;

    for(int i=1; i<=sum; i++)
    {
        dp[0][i] = false;
    }

    for(int i=1; i<=s; i++)
    {
        for(int j = 0; j<=sum; j++)
        {
            if(num[i-1] <= j)
            {
                 dp[i][j] = dp[i-1][j-num[i-1]]|| dp[i-1][j];


            }else
            {
               dp[i][j] =  dp[i-1][j];
            }
        }
    }

    if(dp[s][sum])
    {
        cout<<"Yes"<<endl;

    }
    else
    {
        cout<<"NO"<<endl;
    }
}
