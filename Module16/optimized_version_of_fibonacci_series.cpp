#include<bits/stdc++.h>
using namespace std;

const int N = 200;

int dp[N];

int fibo(int n)
{
    if(n == 0 || n==1)
    {
        return 1;
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }

    int ans = fibo(n-1) + fibo(n-2);

    dp[n] = ans;

    return ans;
}

int main()
{
    int n;
    cin>>n;

    memset(dp,-1,sizeof(dp));

    int res = fibo(n);

    cout<<res<<endl;

}
