#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str1,str2;
    cin>>str1>>str2;

    int n = str1.size();
    int m = str2.size();

    int dp[n+1][m+1];

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {

            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(str1[i-1] == str2[j-1])
            {

                dp[i][j] = dp[i-1][j-1]+1;

            }
            else
            {

                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

            }
        }
    }

    // to check to print

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    int i=n,j=m;

    string ans;

    while(i!=0 && j!=0)
    {
        if(str1[i-1] == str2[j-1])
        {
            ans+=str1[i-1];
            i--;
            j--;
        }
        if(dp[i][j-1] > dp[i-1][j])
        {
            j--;
        }
        else
        {
            i--;
        }
    }

    reverse(ans.begin(),ans.end());

    cout<<ans<<endl;

}
