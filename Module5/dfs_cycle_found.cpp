#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool vis[N];
int parentArray[N];
bool cycle;

void dfs(int src) {
    vis[src] = true;

    for (int child : adjList[src]) {
        // If the child is already visited and not the parent, it's a cycle
        if (vis[child] == true && child != parentArray[src]) {
            cycle = true;
        }
        if (!vis[child]) {
            parentArray[child] = src; // Set parent for the child
            dfs(child);
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    // Input the graph
    while (e--) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    // Initialize visited and parent arrays
    memset(vis, false, sizeof(vis));
    memset(parentArray, -1, sizeof(parentArray));
    cycle = false;

    // Check for cycles in all components
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    // Output the result
    if (cycle) {
        cout << "Cycle Found" << endl;
    } else {
        cout << "Cycle Not Found" << endl;
    }

    return 0;
}
