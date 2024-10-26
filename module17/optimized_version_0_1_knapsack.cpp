#include<bits/stdc++.h>
using namespace std;

const int MaxN = 1000;
const int MaxW = 1000;

int dp[MaxN][MaxW];

int Knapsack(int n,int weight[],int value[],int W)
 {

     if(n <0 || W == 0)
     {
         return 0;
     }
     if(dp[n][W] != -1)
     {
         return dp[n][W];
     }

     if(weight[n] <= W)
     {

         int opt1 = Knapsack(n-1,weight,value,W-weight[n]) + value[n];
         int opt2 = Knapsack(n-1,weight,value,W);

         dp[n][W] = max(opt1,opt2);

         return dp[n][W];
     }else
     {
                  int opt2 = Knapsack(n-1,weight,value,W);
                  return dp[n][W] = opt2;

     }

 }


int main()
{
    int n;
    cin>>n;

    int weight[n],value[n];

    for(int i=0; i<n; i++)
    {
        cin>>weight[i];
    }
    for(int j=0; j<n; j++)
    {
        cin>>value[j];
    }

    int W;
    cin>>W;

    // initial the value

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=W; j++)
        {
            dp[i][j] = -1;
        }
    }

    // print the value

    cout<<Knapsack(n-1,weight,value,W)<<endl;
}
