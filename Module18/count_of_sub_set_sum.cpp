#include<bits/stdc++.h>
using namespace std;



int sub_set_sum_count(int n,int num[],int sum)
{

    if(n==0)
    {
        if(sum==0)
        {
            return 1;

        }
        else
        {
            return 0;
        }
    }

    if(num[n - 1] <= sum)
    {
        int op1 = sub_set_sum_count(n-1,num,sum - num[n-1]);
        int op2 = sub_set_sum_count(n-1,num,sum);

        return op1 + op2;
    }
    else
    {
        int op2 = sub_set_sum_count(n-1,num,sum);
        return op2;
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

    // called the sum;

    cout<<sub_set_sum_count(s,num,sum)<<endl;
}
