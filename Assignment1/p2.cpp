#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin>>n>>e;

    vector<vector<int>> adj(n);

    for (int i = 0; i < e; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x, y;
        cin>>x>>y;


        int flag = 0;

        if (x == y)
        {
            flag = 1;
        }
        else
        {
            for (int child : adj[x])
            {
                if (child == y)
                {
                    flag = 1;
                    break;
                }
            }
        }

        if(flag == 1)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }


}
