#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int kuttingProblem(int n,int w,int weight[],int value[])
{

    if(n == 0 || w==0)
    {
        return 0;
    }

    // for optimized version

    if(dp[n][w] != -1)
    {

        return dp[n][w];
    }


    if(weight[n-1] <= w)
    {

        int op1 = kuttingProblem(n,w-weight[n-1],weight,value) + value[n-1];
        int op2 = kuttingProblem(n-1,w,weight,value);

        return dp[n][w] = max(op1,op2);
    }
    else
    {
        return dp[n][w] = kuttingProblem(n-1,w,weight,value);
    }
}

int main()
{
    int n;
    cin>>n;

    int num[n],weight[n];

    for(int i=0; i<n; i++)
    {
        cin>>num[i];
        weight[i] = i+1;
    }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout<<kuttingProblem(n,n,weight,num)<<endl;
}
