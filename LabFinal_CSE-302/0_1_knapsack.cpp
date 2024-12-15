#include<bits/stdc++.h>
using namespace std;

void knapsack(int num,float weight[],float value[],float capa)
{
    float x[20],tp=0.0;
    float u = capa;
    int i;

    for(i=0; i<num; i++)
    {
        if(weight[i]>u)
        {
            break;
        }
        else
        {
            x[i] = 1.0;
            tp+=value[i];
            u-=weight[i];
        }
    }

    if(i<num)
    {
        x[i] = u/weight[i];
        tp = tp + (x[i] * value[i]);
    }

    cout<<"\nResult vector is : "<<endl;
    for(int i=0; i<num; i++)
    {
        cout<<x[i]<<"\t";
    }

    cout<<"\nMaximum profit is : "<<tp<<endl;
}

int main()
{
    float weight[20],value[20],profit[20],capa;
    int num;

    cout<<"\nEnter the number of items : "<<endl;
    cin>>num;

    cout<<"\nEnter the weight and value for each items : "<<endl;
    for(int i=0; i<num; i++)
    {
        cin>>weight[i]>>value[i];
    }

    cout<<"\nEnter the capacity of knapsack : "<<endl;
    cin>>capa;

    // to find the profit

    for(int i=0; i<num; i++)
    {
        profit[i] = value[i]/weight[i];
    }

    for(int i=0; i<num; i++)
    {
        for(int j=i+1; j<num; j++)
        {
            if(profit[i]<profit[j])
            {
                swap(profit[j],profit[i]);
                swap(weight[j],weight[i]);
                swap(value[j],value[i]);
            }
        }
    }

    knapsack(num,weight,value,capa);

    return 0;
}
