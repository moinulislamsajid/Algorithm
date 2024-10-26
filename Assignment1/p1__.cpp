#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int>adjList[N];


int main()
{
    int n,e;
    cin>>n>>e;

    for(int i=0; i<e; i++)
    {
        int a,b;
        cin>>a>>b;

        adjList[a].push_back(b);


    }

    int q;
    cin>>q;

    while(q--)
    {
        int a,b;
        cin>>a>>b;

        int flag = 0;

        if(a == b)
        {
            flag =1;
        }
        else
        {
            for(int child : adjList[a])
            {
                if(child == b)
                {
                    flag =  1;
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
