#include<bits/stdc++.h>
using namespace std;

bool vis[100][100];
int dis[100][100];
int r,c;

char name[20][20];

vector<pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};

bool valid(int i,int j)
{
    if(i<0 || i>=r || j<0 || j>=c)
    {

        return false;
    }
    else
    {
        return true;
    }


}

void bfs(int ci,int cj)
{

    queue<pair<int,int>> q;
    q.push({ci,cj});
    vis[ci][cj] = true;
    dis[ci][cj] = 0;
    while(!q.empty())
    {
        pair<int,int> pr = q.front();
        int fir = pr.first;
        int sec = pr.second;
        q.pop();


        cout<<fir<<" "<<sec<<endl;

        for(int i=0; i<4; i++)
        {

            int ci = pr.first + v[i].first;
            int cj = pr.second + v[i].second;

            if(valid(ci,cj) == true && vis[ci][cj] == false)
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[fir][sec] + 1;
            }
        }


    }
}


int main()
{

    cin>>r>>c;


    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            cin>>name[i][j];
        }

    }


    int si,sj;
    cin>>si>>sj;

    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));

    bfs(si,sj);

}
