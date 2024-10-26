#include<bits/std++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>num[n]; // this is adjacency matrix

    while(e--)
    {
        int a,b;
        cin>>a>>b;
        num[a].push_back(b);
        num[b].push_back(a);
    }

    for(int H : num[0])
    {
        cout<<H<<" ";
    }
}
