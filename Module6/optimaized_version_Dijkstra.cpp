#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<pair<int,int>> adj[N];
int dis[N];

class cmd
{
public :
    bool operator ()(pair<int,int> a, pair<int,int> b)
    {
        return a.second > b.second; // Compare based on cost
    }
};

void dijkstra(int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmd> pq;
    pq.push({src, 0});
    dis[src] = 0;

    while(!pq.empty())
    {
        pair<int,int> prt = pq.top();
        pq.pop();

        int prtNode = prt.first;
        int prtCost = prt.second;

        for(pair<int,int> child : adj[prtNode])
        {
            int childNode = child.first;
            int childCost = child.second;

            if(prtCost + childCost < dis[childNode])
            {
                dis[childNode] = prtCost + childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while(e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    for(int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    int src;
    cin >> src;

    // Call the function
    dijkstra(src);

    // Print the distance values
    for(int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }
}
