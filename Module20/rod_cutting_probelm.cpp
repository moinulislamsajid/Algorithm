#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int dp[N][N];

int rod_Cutting(int n,int w,int weight[],int value)
{

    if(n==0 || w==0)
    {
        return 0;
    }

    if(dp[n][w] != -1)
    {
        return dp[n][w];
    }

    if(weight[n-1] <= w)
    {
        int op1 = rod_Cutting(n,w-weight[n-1],weight,value) + value[n-1];
        int op2 = rod_Cutting(n-1,w,weight,value);

        return dp[n][w] = max(op1,op2);
    }
    else
    {
        return dp[n][w] = rod_Cutting(n-1,w,weight,value);
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

   for(int i=0; i<n; i++)
   {
       for(int j=0; j<n; j++)
       {
           dp[i][j] = -1;
       }
   }

    cout<<rod_Cutting(n,w,weight,value)<<endl;


}
