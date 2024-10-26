#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int num[n];
        int sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>num[i];
            sum+=num[i];
        }



        int diff = abs(1000-m);
        int fsum = (sum+diff)/2;

        if(fsum%2==0)
        {

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
                        dp[i][j] = dp[i-1][j-num[i-1]] || dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i-1][j];
                    }

                }
            }

            if(dp[n][fsum])
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
}
