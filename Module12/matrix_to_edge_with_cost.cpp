#include<bits/stdc++.h>
using namespace std;

class Edge
{
public :

    int u,v,c;

    Edge(int u,int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

int main()
{
    int n;
    cin>>n;
    int mat[n][n];
    for(int i = 0;i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {

            cin>>mat[i][j];
        }
    }

    vector<Edge> v;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(mat[i][j] > 0)
            {
                v.push_back(Edge(i,j,mat[i][j]));
            }
        }
    }

    for(Edge ed : v)
    {
        cout<<ed.u<<" "<<ed.v<<" "<<ed.c<<endl;
    }
}
