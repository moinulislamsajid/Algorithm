#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
bool vis[N][N];
int dis[N][N];
int n,m;
char num[N][N];
vector<pair<int,int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};
bool valid(int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=m)
    {
        return false;
    }

    return true;
}

void bfs(int si,int sj)
{

    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while(!q.empty())
    {
        pair<int,int> part = q.front();

        int a = part.first;
        int b = part.second;
        q.pop();

        cout<<a<<" "<<b<<endl;

        for(int i=0; i<4; i++)
        {
            int childI = a + dir[i].first;
            int childJ = b + dir[i].second;

            if(valid(childI,childJ) == true && vis[childI][childJ] == false)
            {
                q.push({childI,childJ});
                vis[childI][childJ] = true;
                dis[childI][childJ] = dis[a][b] + 1;
            }
        }
    }

}


int main()
{

   cin>>n>>m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>num[i][j];
        }
    }

    int si,sj;
    cin>>si>>sj;

    // to set the initial value

    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));

    // called the function

    bfs(si,sj);

    cout<<dis[0][3]<<endl;
}
