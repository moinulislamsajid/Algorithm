#include<bits/stdc++.h>
using namespace std;


int r,c;

vector<vector<bool>>vis;
vector<pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};

bool valid(int x,int y,vector<vector<char>>& play)
{

    return x>=0 && x<r && y >= 0 && y<c && play[x][y] != '#' && !vis[x][y];

}

void bfs(int i,int j,vector<vector<char>> & play)
{

    queue<pair<int,int>> q;
    q.push({i,j});
    vis[i][j] = true;

    while(!q.empty())
    {
        pair<int,int> pr = q.front();
        int st = pr.first;
        int sec = pr.second;
        q.pop();

        for(auto child : v)
        {
            int f =  st + child.first;
            int s = sec + child.second;

            if(valid(f,s,play))
            {
                q.push({f,s});
                vis[f][s] = true;
            }
        }
    }


}


int main()
{
    cin>>r>>c;
    vector<vector<char>> play(r,vector<char>(c));

    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            cin>>play[i][j];
        }
    }



    int cnt =0;

    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            if(play[i][j] == '.' && !vis[i][j])
            {
                bfs(i,j,play);
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;


}
