#include<bits/stdc++.h>
using namespace std;

int r,c;

vector<vector<bool>> vis;
vector<pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};

bool valid(int x,int y,vector<vector<char>> &play)
{
    return x>=0 && x<r && y>=0 && y<c && play[x][y] == '.' && !vis[x][y];
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
            q.pop();

            int fv = prt.first;
            int sv = prt.second;

            for(pair<int,int> child : v)
            {
                int nvx = fv + child.first;
                int nvy = sv + child.second;

                if(valid(nvx,nvy,play))
                {
                    q.push({nvx,nvy});
                    vis[nvx][nvy] = true;
                    area++;
                }
            }
        }

    return area;
}



int main()
{
    cin>>r>>c;

    vector<vector<char>> play (r,vector<char>(c));
    vis.resize(r,vector<bool>(c,false));


    for(int i=0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            cin>>play[i][j];
        }
    }


    int minValue = INT_MAX;
    bool com = false;



    for(int i= 0; i<r; i++)
    {

        for(int j = 0; j<c; j++)
        {
            if(play[i][j] == '.' && !vis[i][j])
            {
                com = true;
                int area = bfs(i,j,play);
                minValue = min(minValue,area);

            }
        }
    }

    if(com)
    {
        cout<<minValue<<endl;
    }else
    {
        cout<<-1<<endl;
    }

}
