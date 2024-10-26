#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

int dp[N][N];

bool set_optimized(int n,int num[],int sum)
{

    // base case

    if(n==0)
    {
        if(sum == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(dp[n][sum])
    {
        return dp[n][sum];
    }

    if(num[n-1] <= sum)
    {
        bool op1 = set_optimized(n-1,num,sum - num[n-1]);
        bool op2 = set_optimized(n-1,num,sum);

        return dp[n][sum] = op1 || op2;
    }
    else
    {
        return dp[n][sum] = set_optimized(n-1,num,sum);
    }

}

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

    // called the function

    if(set_optimized(s,num,sum))
    {
        cout<<"YES"<<endl;
    }else
    {
        cout<<"N0"<<endl;
    }


}
