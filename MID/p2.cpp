#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({v, cost});
    }

    int source;
    cin >> source;

    vector<int> min_cost(n + 1, INT_MAX);
    min_cost[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        int current_cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (current_cost > min_cost[node]) continue;

        for (auto neighbor : adj[node])
        {
            int next_node = neighbor.first;
            int edge_cost = neighbor.second;

            if (current_cost + edge_cost < min_cost[next_node])
            {
                min_cost[next_node] = current_cost + edge_cost;
                pq.push({min_cost[next_node], next_node});
            }
        }
    }

    int t;
    cin >> t;

    while (t--)
    {
        int destination, max_cost;
        cin >> destination >> max_cost;

        if (min_cost[destination] <= max_cost)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

