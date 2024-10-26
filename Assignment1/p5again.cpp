#include<bits/stdc++.h>
using namespace std;
int r,c;

vector<vector<bool>> vis;
vector<pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};

bool valid(int x,int y,vector<vector<char>> & play)
{
    return x>=0 && x<r && y>=0 && play[x][y] == '.' && !vis[x][y];
}

int bfs(int st,int en,vector<vector<char>> &play)
{


    queue<pair<int,int>>q;
    q.push({st,en});
    vis[st][en] = true;
    int cnt = 0;
    while(!q.empty())
    {
        pair<int,int> prt = q.front();
        int f = prt.first;
        int s = prt.second;
        q.pop();
        cnt++;

        for(auto child : v)
        {
            int ft = f + child.first;
            int st = s + child.second;

            if(valid(ft,st,play))
            {
                q.push({ft,st});
                vis[ft][st] = true;
            }
        }

    }

    return cnt;
}




int main()
{
    cin>>r>>c;

    vector<vector<char>> play(r,vector<char>(c));

    for(int i=0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            cin>>play[i][j];
        }
    }

    vis.assign(r,vector<bool>(c,false));

    vector<int> vn;
    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            if(play[i][j] == '.' && vis[i][j] == false)
            {
                int value = bfs(i,j,play);
                vn.push_back(value);

            }
        }
    }

    if(vn.empty())
    {
        cout<<0<<endl;
    }else
    {
        sort(vn.begin(),vn.end());

        for(int h : vn)
        {
            cout<<h<<" ";
        }
    }

    cout<<endl;

}
