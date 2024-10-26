#include<bits/stdc++.h>
using namespace std;


int main()
{

    // for input node and edge

    int node,edge;
    cin>>node>>edge;

    // declared two Dimensonal arrays

    int number[node][node];

    // initial for 2 D arrays

    memset(number,0,sizeof(number));

    while(edge--)
    {

        // input two values

        int a,b;
        cin>>a>>b; // this a,b is determine index value

        number[a][b] = 1;
        number[b][a] = 1;


    }

    for(int i = 0; i<node; i++)
    {
        for(int j = 0; j<node; j++)
        {
            cout<<number[i][j]<<" ";
        }
        cout<<endl;
    }

    if(number[1][4] == 1)
    {
        cout<<"Connection Ache"<<endl;
    }else
    {
        cout<<"Connection Nai"<<endl;
    }
}
