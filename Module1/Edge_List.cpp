#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>>v;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }

    // print the value

    /*for(int i = 0; i<v.size(); i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<" "<<endl;
    }*/


    // using for each loop

    for(pair<int,int> pp : v)
    {
        cout<<pp.first<<" "<<pp.second<<" "<<endl;
    }
}
