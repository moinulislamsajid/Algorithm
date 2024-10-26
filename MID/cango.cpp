#include <bits/stdc++.h>
using namespace std;

const long long   value = 1e5+5;
const int MN = 1005;

int u[MN], v[MN];
long long w[MN];
long long peo[MN];
int n, m;

bool bellmanFord(int source)
{
    peo[source] = 0;


    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (peo[u[j]] != value && peo[u[j]] + w[j] < peo[v[j]])
            {
                peo[v[j]] = peo[u[j]] + w[j];
            }
        }
    }


    for (int j = 0; j < m; j++)
    {
        if (peo[u[j]] != value && peo[u[j]] + w[j] < peo[v[j]])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;


    for (int i = 0; i < m; i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }

    int s;
    cin>>s;


    fill(dist, dist + n + 1, INF);


    if (!bellmanFord(source))
    {
        cout << "Negative Cycle Detected\n";
        return 0;
    }

    int q;
    cin >> q;


    while (q--)
    {
        int d;
        cin >> d;

        if (peo[d] == value)
        {
            cout << "Not Possible\n";
        }
        else
        {
            cout << peo[d] << endl;
        }
    }


}

