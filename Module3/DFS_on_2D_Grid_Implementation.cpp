#include<bits/stdc++.h>
using namespace std;
int r,c;
char name[20][20];
bool vis[20][20];
vector<pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};

bool valid(int i,int j)
{
    if(i<0 || i>=r || j<0 || j>=c)
    {

        return false;
    }else
    {
        return true;
    }


}


void dfs(int si,int sj)
{

    cout<<si<<" "<<sj<<endl;
    vis[si][sj] = true;

    for(int i = 0; i<4; i++)
    {
        int ci = si + v[i].first;
        int cj = sj + v[i].second;

        if(valid(ci,cj) == true && vis[ci][cj] == false)
        {
            dfs(ci,cj);
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

    int s1,s2;
    cin>>s1>>s2;
    memset(vis,false,sizeof(vis));
    dfs(s1,s2);

}
