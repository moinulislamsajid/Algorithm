#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int lcs(string str1,int n,string str2,int m)
{

    if(n==0 || m==0)
    {
        return 0;
    }

    if(dp[n][m] != -1)
    {
        return dp[n][m];
    }

    if(str1[n-1] == str2[m-1])
    {
        int ans = lcs(str1,n-1,str2,m-1);
        return dp[n][m] = ans+1;
    }
    else
    {
        int op1 = lcs(str1,n-1,str2,m);
        int op2 = lcs(str1,n,str2,m-1);

        return dp[n][m] = max(op1,op2);
    }

}

int main()
{
    string str1,str2;
    cin>>str1>>str2;

    for(int i=0; i<=str1.size(); i++)
    {
        for(int j=0; j<=str2.size(); j++)
        {
            dp[i][j] = -1;
        }
    }

    cout<<lcs(str1,str1.size(),str2,str2.size());
}
