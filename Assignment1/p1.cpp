#include<bits/stdc++.h>
using namespace std;

int main()
{
    int  n,e;
    cin>>n>>e;
    vector<int> v[n];

    while(e--)
    {
        int a,b;
        cin>>a>>b;

        v[a].push_back(b);


    }

    int q;
    cin>>q;

    while(q--)
    {
        int x,y;
        cin>>x>>y;

        int flag = 0;
        for(int child : v[x])
        {

            if(child == y || x == y)
            {
                flag = 1;
                break;
            }

        }

        if(flag == 1)
        {
            cout<<"YES"<<endl;
        }else
        {
            cout<<"NO"<<endl;
        }

    }




}
