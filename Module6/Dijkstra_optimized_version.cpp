#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<pair<int,int>> adjList[N];
int dis[N];

void dijkstra(int src)
{

}

int main()
{
    int n,e;
    cin>>n>>e;

    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;

        adjList[a].push_back({b,c});
        adjList[b].push_back({a,c});
    }

    for(int i=0; i<n; i++)
    {
        dis[i] = INT_MAX;
    }

    int src;
    cin>>src;

    // called the function

     dijkstra(src);

     // print the value

     for(int i=0; i<n; i++)
     {
         cout<<i<<"-> "<<dis[i]<<endl;
     }
}
