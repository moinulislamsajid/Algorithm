#include<bits/stdc++.h>
using namespace std;

int UnboundKnapsack(int n,int weight[],int value[],int w)
{

    // base case

    if(n==0 || w==0)
    {
        return 0;
    }

    if(weight[n-1] <= w)
    {
        int op1 = UnboundKnapsack(n,weight,value,w-weight[n-1]) + value[n-1];
        int op2 = UnboundKnapsack(n-1,weight,value,w);

        return max(op1,op2);
    }
    else
    {
        return UnboundKnapsack(n-1,weight,value,w);
    }

}

int main()
{
    int v,w;
    cin>>v>>w;

    int value[v],weight[v];

    for(int i=0; i<v; i++)
    {
        cin>>value[i];
    }

    for(int j=0; j<v; j++)
    {
        cin>>weight[j];
    }

    cout<<UnboundKnapsack(v,weight,value,w);
}
