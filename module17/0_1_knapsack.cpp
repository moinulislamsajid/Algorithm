#include<bits/stdc++.h>
using namespace std;

int Knapsack(int n,int weight[],int value[],int W)
{
    if(n<0 || W==0)
    {
        return 0;
    }

    if(weight[n]<=W)
    {
        int opt1 = Knapsack(n-1,weight,value,W-weight[n]) + value[n];
        int opt2 = Knapsack(n-1,weight,value,W);

        return max(opt1,opt2);
    }
    else
    {
                int opt2 = Knapsack(n-1,weight,value,W);
                return opt2;


    }
}

int main()
{
    int n,W;
    cin>>n>>W;

    int weight[n],value[n];

    // to get the weight input

    for(int i=0; i<n; i++)
    {
        cin>>weight[i]>>value[i];
    }



    // now print the recursive

    cout<<Knapsack(n-1,weight,value,W)<<endl;
}
