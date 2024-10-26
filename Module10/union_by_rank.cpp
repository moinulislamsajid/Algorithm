#include <iostream>
using namespace std;

const int N = 1e5 + 5;

int parent[N];
int level[N];
int sizeOf[N];

void initial_DSU(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        level[i] = 0;      // This represents rank, used for union by rank.
        sizeOf[i] = 1;     // Initialize size of each set to 1.
    }
}

int findLeader(int node)
{
    if (parent[node] == -1)
    {
        return node;
    }

    // Path compression to optimize find operation
    int leader = findLeader(parent[node]);
    parent[node] = leader;
    return leader;
}

void rank_by_size(int node1, int node2)
{
    int leaderA = findLeader(node1);
    int leaderB = findLeader(node2);

    // If both nodes have the same leader, they are already in the same set
    if (leaderA == leaderB)
        return;

    // Union by size: attach the smaller tree under the larger one
    if (sizeOf[leaderA] > sizeOf[leaderB])
    {
        parent[leaderB] = leaderA;
        sizeOf[leaderA] += sizeOf[leaderB];  // Update size of the new root
    }
    else
    {
        parent[leaderA] = leaderB;
        sizeOf[leaderB] += sizeOf[leaderA];  // Update size of the new root
    }
}

int main()
{
    initial_DSU(7);  // Initialize DSU for 7 elements (0 to 6)

    // Union operations
    rank_by_size(1, 2);
    rank_by_size(1, 2);  // This union is redundant but will work fine
    rank_by_size(2, 3);
    rank_by_size(4, 5);
    rank_by_size(5, 6);
    rank_by_size(1, 4);

    // Find operations
    cout << findLeader(1) << endl;
    cout << findLeader(4) << endl;

    return 0;
}
