#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str1,str2;
    cin>>str1>>str2;

    int s1 = str1.size();
    int s2 = str2.size();

    int dp[s1+1][s2+1];

    for(int i=0; i<=s1; i++)
    {
        for(int j=0; j<=s2; j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for(int i=1; i<=s1; i++)
    {
        for(int j=1; j<=s2; j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    cout<<dp[s1][s2]<<endl;
}
