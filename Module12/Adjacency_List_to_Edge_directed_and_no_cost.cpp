#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n,e;
    cin>>n>>e;

    vector<int> adjList[n];

    while(e--)
    {
        int a,b;
        cin>>a>>b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    // create a vector pair type

    vector<pair<int,int>> edgeList;

    for(int i=0; i<n; i++)
    {
        for(pair<int,int> child : adjList[i])
        {
            if(i < child) // to avoid duplicates
            {
                edgeList.push_back({i,child});
            }
        }
    }

    // now print the value

    for(pair<int,int> value : edgeList)
    {
        cout<<value.first<<" "<<value.second<<endl;
    }
}
