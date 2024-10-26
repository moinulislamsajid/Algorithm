#include<bits/stdc++.h>
using namespace std;

vector<vector<bool>> vis;

vector<pair<int,int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};

 int r,c;

 bool valid(int x,int y,vector<vector<char>> &play)
 {
     return x>=0 && x<r && y>=0 && y<c && play[x][y] != '#' && !vis[x][y];
 }


 void bfs(int sx,int sy,vector<vector<char>> &play)
 {


     queue<pair<int,int>> q;
     q.push({sx,sy});
     vis[sx][sy] = true;

     while(!q.empty())
     {
         pair<int,int> prt = q.front();

         int r = prt.first;
         int s = prt.second;

         for(auto child : dir)
         {
             int lf = r + child.first;
             int ls = s + child.second;

             if(valid(lf,ls,play))
             {
                 q.push({lf,ls});
                 vis[lf][ls] = true;
             }
         }
     }
 }

int main()
{

    cin>>r>>c;

    vector<vector<char>>play(r,vector<char>(c));
    vis.resize(r,vector<bool> (c,false));

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>play[i][j];
        }
    }

    int cn=0;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(play[i][j] == '.' && vis[i][j] == false)
            {
                bfs(i,j,play);
                cn++;
            }
        }
    }

    cout<<cn<<endl;

}
