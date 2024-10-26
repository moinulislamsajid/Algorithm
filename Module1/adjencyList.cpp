#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>num[n];

    while(e--)
    {
        int a,b;
        cin>>a>>b;

        num[a].push_back(b);
        num[b].push_back(a);
    }

    for(auto k : num  [0])
    {
        cout<<k<<" ";
    }
}
