#include<bits/stdc++.h>
using namespace std;

bool sub_set(int n,int num[],int sum)
{
    // base case

    if(n == 0)
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

    if(num[n-1] <= sum)
    {
        bool op1 = sub_set(n-1,num,sum - num[n-1]);
        bool op2 = sub_set(n-1,num,sum);

        return op1 || op2;
    }
    else
    {
        return sub_set(n-1,num,sum);


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

    if(sub_set(s,num,sum))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
