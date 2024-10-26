#include<bits/stdc++.h>
using namespace std;
int r,c;
char name[100][100];
bool vis[100][100];
vector<pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};

bool valid(int i, int j)
{
    if(i<0 || i>=r || j<0 || j>=c)
    {
        return false;
    }else
    {
        return true;
    }
}

void dfs(int ai,int aj)
{
    cout<<ai<<" "<<aj<<endl;
    vis[ai][aj] = true;

    for(int i=0; i<4; i++)
    {
        int ci = ai + v[i].first;
        int cj = aj + v[i].second;

        if(valid(ci,cj) == true && vis[ci][cj] == false)
        {
            dfs(ci,cj);
        }
    }
}

int main()
{
    cin>>r>>c;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>name[i][j];
        }
    }

    int si,sj;
    cin>>si>>sj;

    memset(vis,false,sizeof(vis));

    // called the function

    dfs(si,sj);


}
