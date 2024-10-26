#include<bits/stdc++.h>
using namespace std;

 int main()
 {
     int n,e;
     cin>>n>>e;

     vector<pair<int,int>> v;

     while(e--)
     {
         int a,b;
         cin>>a>>b;

         v.push_back({a,b});
     }

     // print the edgelist

     for(int i=0; i<v.size(); i++)
     {
         cout<<v[i].first<<" "<<v[i].second<<endl;
     }

     // print range base for loop

     for(pair<int,int> child : v)
     {
         cout<<child.first<<" "<<child.second<<endl;
     }
 }
