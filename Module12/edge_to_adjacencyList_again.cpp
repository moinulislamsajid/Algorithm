#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;

    vector<int> edge[n];

    while(e--)
    {
        int a,b;
        cin>>a>>b;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for(int i = 0; i<n; i++)
    {
        cout<<i<<"-> ";

        for(int child : edge[i])
        {
            cout<<child<<" ";
        }

        cout<<endl;
    }

}
