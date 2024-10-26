#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
const int M = 1005;

char num[N][M];
int n,m;
bool vis[N][M];

vector<pair<int,int>> direc = {{0,1},{0,-1},{-1,0},{1,0}};

bool valid(int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=m)
    {
        return false;
    }

    return true;

}

void usingDFS(int si,int sj)
{

    cout<<si<<" "<<sj<<endl;
    vis[si][sj] = true;


    for(int i=0; i<4; i++)
    {
        // now we find child

        int childI = si+ direc[i].first;
        int childJ = sj + direc[i].second;

        if(valid(childI,childJ) == true && vis[childI][childJ] == false)
        {
            usingDFS(childI,childJ);
        }
    }

}



int main()
{

    cin>>n>>m;

    for(int i=0; i<n; i++)
    {
        for(int j =0; j<m; j++)
        {
            cin>>num[i][j];
        }
    }

    int si,sj;
    cin>>si>>sj;


    // called the function

    usingDFS(si,sj);
}
