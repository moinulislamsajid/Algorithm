#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int parent[N];
int levelrank[N];
int removeEdge = 0;

void DSU_init(int n) {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        levelrank[i] = 0;
    }
}

int findLeader(int node) {
    if (parent[node] != node) {
        parent[node] = findLeader(parent[node]);
    }
    return parent[node];
}

void union_by_rank(int node1, int node2) {
    int leader1 = findLeader(node1);
    int leader2 = findLeader(node2);

    if (leader1 != leader2) {
        if (levelrank[leader1] > levelrank[leader2]) {
            parent[leader2] = leader1;
        } else if (levelrank[leader1] < levelrank[leader2]) {
            parent[leader1] = leader2;
        } else {
            parent[leader2] = leader1;
            levelrank[leader1]++;
        }
    }
}

class Edge {
public:
    int u, v, c;
    Edge(int u, int v, int c) {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

bool cmp(Edge a, Edge b) {
    return a.c < b.c;
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<Edge> edgeList;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edgeList.push_back(Edge(a, b, c));
    }


    DSU_init(n);

    sort(edgeList.begin(), edgeList.end(), cmp);

    int minCost = 0;
    int edgesUsed = 0;

    for (Edge ed : edgeList) {
        int firstLeader = findLeader(ed.u);
        int secondLeader = findLeader(ed.v);

        if (firstLeader != secondLeader) {
            union_by_rank(ed.u, ed.v);
            minCost += ed.c;
            edgesUsed++;
        } else {
            removeEdge++;
        }
    }

    if (edgesUsed != n - 1) {
        cout << "Not Possible" << endl;
    } else {
        cout << removeEdge << " " << minCost << endl;
    }

}
