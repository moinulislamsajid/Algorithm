#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<pair<int,int>> adj[N];
int dist[N];

void dijkstra(int src)
{

    queue<pair<int,int>> q;

    q.push({src,0});
    dist[src] = 0;

    while(!q.empty())
    {

        pair<int,int> pr = q.front();
        q.pop();
        int node = pr.first;
        int ParentCost = pr.second;

        for(pair<int,int> child : adj[node])
        {

            int childNode = child.first;
            int childCost = child.second;

            if(ParentCost + childCost < dist[childNode])
            {

                dist[childNode] = ParentCost + childCost;
                q.push({childNode,dist[childNode]});
            }
        }

    }

}

int main()
{
    int n,e;
    cin>>n>>e;

    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;

        adj[a].push_back({b,c}); // push to the pair value
        adj[b].push_back({a,c});
    }

    //  set all value for maximum

    for(int i = 0; i<n; i++)
    {
        dist[i] = INT_MAX;

    }

    // called the function
    int src;
    cin>>src;
    dijkstra(src);

    // print maximum value

    for(int i=0; i<n; i++)
    {
        cout<<i<<"->"<<dist[i]<<endl;
    }
}
