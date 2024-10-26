#include<bits/stdc++.h>
using namespace std;
int r,c;
vector<vector<bool>>vis;
vector<pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};

bool valid(int x,int y,vector<vector<char>>& play)
{

    return x>=0 && x<r && y >= 0 && y<c && play[x][y] == '.' && !vis[x][y];

}

int bfs(int i,int j,vector<vector<char>> &play)
{

        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = true;
        int area = 1;

        while(!q.empty())
        {
            pair<int,int> prt = q.front();

            int st = prt.first;
            int sec = prt.second;
            q.pop();

            for(pair<int,int> child : v)
            {
                int f =  st  +  child.first;
                int s =  sec + child.second;

                if(valid(f,s,play))
                {
                    q.push({f,s});
                    vis[f][s] = true;
                    area++;
                }
            }
        }

        return area;

}

int main()
{

   cin>>r>>c;
   vector<vector<char>> play(r,vector<char> (c));
   vis.resize(r, vector<bool>(c, false));

   for(int i=0; i<r; i++)
   {
       for(int j=0; j<c; j++)
       {
           cin>>play[i][j];
       }
   }

   int minArea = INT_MAX;
   bool comp = false;


   for(int i = 0; i<r; i++)
   {
       for(int j = 0; j<c; j++)
       {
           if(play[i][j] == '.' && !vis[i][j])
           {
               comp = true;
               int area = bfs(i,j,play);
               minArea = min(minArea,area);
           }
       }
   }

   if(comp)
   {
       cout<<minArea<<endl;
   }else
   {
       cout<<-1;
   }
}
