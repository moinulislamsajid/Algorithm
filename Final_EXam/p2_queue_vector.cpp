#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int dp[N];


bool find_value(int curr,int key)
{

    if(curr == key)
    {
        return true;
    }

    if(curr > key)
    {
        return false;
    }

    if(dp[curr] !=-1)
    {
        return dp[curr];
    }

    return dp[curr] = find_value(curr+3,key) || find_value(curr*2,key);
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        memset(dp,-1,sizeof(dp));

        if(find_value(1,n))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }


}
