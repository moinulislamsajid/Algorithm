#include <bits/stdc++.h>
#define ll long long int
using namespace std;


const long long   mvalue =1e5+5;
vector<pair<long long,long long>>vec[mvalue];

long long  can[mvalue];


class ADD
{
public:
    bool operator()(pair<long, long >add, pair<long,long>after)
    {
        if(add.second>after.second)
        {
            return true;

        }
         else
         {
              return false;
         }

    }
};
void ALgo(int src)
{
    priority_queue<pair<long,long>, vector<pair<long,long>>,ADD>pq;
    pq.push({src, 0});
    can[src]=0;
    while(!pq.empty())
    {
        pair<long,long>pr=pq.top();
        pq.pop();
        long a=pr.first;
        long b=pr.second;

        for(auto child:vec[a])
        {
            ll cn=child.first;
            ll cs=child.second;
            if((b+cs)<can[cn])
            {
                can[cn]=b+cs;
                pq.push({cn, can[cn]});
            }
        }
    }
}
int main()
{
    long long n, e;
    cin>>n>>e;
    while(e--)
    {
        long long a,b, c;
        cin>>a>>b>>c;
        vec[a].push_back({b,c});
    }
    for(int i=1; i<=n; i++)
    {
        can[i]=INT_MAX;
    }
    ll src, t;
    cin>>src>>t;
    while(t--)
    {
        ALgo(src);
        long long nd,ct;
        cin>>nd>>ct;
        if(can[nd]<=ct)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }

}
