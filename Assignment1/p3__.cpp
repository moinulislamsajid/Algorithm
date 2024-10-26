#include<bits/stdc++.h>
using namespace std;

vector<vector<bool>> vis;
int r,c;
vector<pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};

bool valid(int x,int y,vector<vector<char>>&play)
{

    return x>=0 && x<r && y>=0 && y<c && play[x][y] != '#' && !vis[x][y];

}

bool bfs(int sr,int sc,int tr,int tc,vector<vector<char>> &play)
{

    queue<pair<int,int>> q;
    q.push({sr,sc});
    vis[sr][sc] = true;

    while(!q.empty())
    {

        pair<int,int> prt = q.front();

        int trow = prt.first;
        int tcol = prt.second;

        if(sr == trow && sc == tcol)
        {
            return true;
        }

        for(pair<int,int> child : v)
        {
            int upr = trow + child.first;
            int upc = tcol + child.second;

            if(valid(upr,upc,play))
            {
                q.push({upr,upc});
                vis[upr][upc] = true;
            }
        }
    }

    return false;
}

int main()
{
    cin>>r>>c;


    vector<vector<char>>play(r,vector<char>(c));
    vis.resize(r,vector<bool> (c,false));

    int sr=0,sc=0,tr=0,tc=0;


    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>play[i][j];
        }
    }

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(play[i][j] == 'A')
            {
                sr=i;
                sc=j;
            }
            if(play[i][j] == 'B')
            {
                tr=i;
                tc=j;
            }
        }
    }


    if(bfs(sr,sc,tr,tc,play))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;N
    }






}
