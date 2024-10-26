#include<bits/stdc++.h>
using namespace std;

vector<vector<bool>> vis;
int r,c;

vector<pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};

bool valid(int x,int y,vector<vector<char>>& play)
{

    return x>=0 && x<r && y >= 0 && y<c && play[x][y] != '#' && !vis[x][y];

}

bool bfs(int sx,int sy,int tx,int ty,vector<vector<char>>& play)
{

    queue<pair<int,int>> q;

    q.push({sx,sy});
    vis[sx][sy] = true;

    while(!q.empty())
    {
        pair<int,int> pr = q.front();


        int fir = pr.first;
        int sec = pr.second;
        q.pop();

        if(fir == tx && sec == ty)
        {
            return true;
        }

        for(auto child : v)
        {
            int n = fir + child.first;
            int s = sec + child.second;

            if(valid(n,s,play))
            {
                q.push({n,s});
                vis[n][s] = true;
            }
        }
    }

    return false;

}
 int main()
 {
    cin>>r>>c;
    vector<vector<char>> play(r, vector<char>(c));
    vis.resize(r, vector<bool>(c, false));

    int sx = -1,sy = -1,tx = -1,ty = -1;

    for(int i=0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            cin>>play[i][j];
        }
    }

    for(int i = 0; i<r; i++)
    {
        for(int j  = 0; j<c; j++)
        {
            if(play[i][j] == 'A')
            {
                sx = i;
                sy = j;
            }else if(play[i][j] == 'B')
            {
                tx = i;
                ty = j;
            }
        }
    }



     if(bfs(sx,sy,tx,ty,play))
     {
         cout<<"YES"<<endl;
     }else
     {
         cout<<"NO"<<endl;
     }

 }
