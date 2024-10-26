#include<bits/stdc++.h>
using namespace std;

int lcs(string str1,int n,string str2,int m)
{
    // base case

    if(n==0 || m==0)
    {
        return 0;
    }

    if(str1[n-1] == str2[m-1])
    {
        int ans = lcs(str1,n-1,str2,m-1);

        return ans+1;
    }
    else
    {
        int op1 = lcs(str1,n-1,str2,m);
        int op2 = lcs(str1,n,str2,m-1);

        return max(op1,op2);
    }


}

int main()
{
    string str1,str2;
    cin>>str1>>str2;

    cout<<lcs(str1,str1.size(),str2,str2.size())<<endl;
}
