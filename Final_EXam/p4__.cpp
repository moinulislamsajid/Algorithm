#include<bits/stdc++.h>
using namespace std;

const int max_N = 1e3+5;
const int max_T = 1e5+5;

bool dp[max_N][max_T];

bool find_test(int n,int target,int num[])
{


    dp[0][0] = true;

    for(int i=1; i<=target; i++)
    {
        dp[0][i] = false;
    }


    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=target; j++)
        {
            if(num[i-1] <=target)
            {
                return dp[i][j] = dp[i-1][j-num[i-1]] || dp[i-1][j];
            }
            else
            {
                return dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][target];

}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;

        int num[n];
        for(int i=0; i<n; i++)
        {
            cin>>num[i];
        }

        int target = 1000-k;

        if(target < 0)
        {
            cout<<"NO"<<endl;

        }else
        {
            if(find_test(n,target,num))
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }

    }
}
