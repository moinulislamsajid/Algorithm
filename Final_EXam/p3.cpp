#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int N;
        cin>>N;

        int num[N];
        int sum=0;

        for(int i=0; i<N; i++)
        {
            cin>>num[i];
            sum+=num[i];
        }

        if(sum%2==0)
        {
            int mid = sum/2;
            bool dp[N+1][mid+1];
            dp[0][0] = true;

            for(int i=1; i<=mid; i++)
            {
                dp[0][i] = false;
            }

            for(int i=1; i<=N; i++)
            {
                for(int j=0; j<=mid; j++)
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

            if(dp[N][mid])
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
