 #include<bits/stdc++.h>
using namespace std;

vector<int>v[1000];
bool vis[1000];
int level[1000];
int prt[1000];

void bfs(int src)
{
    queue<pair<int,int>>q;
    q.push({src,0});
    vis[src] = true;
    //level[src] = 0;

    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();

        int pr = p.first;
        int le = p.second;

        //cout<<pr<<endl;


        for(int child : v[pr])
        {
            if(vis[child]==false)
            {

                q.push({child,le+1});
                vis[child] = true;
                level[child] = level[pr]+1;
                prt[child] = pr;
            }
        }
    }
}

int main()
{
    int n,e;
    cin>>n>>e;

    while(e--)
    {
        int a,b;
        cin>>a>>b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    int src,des;
    cin>>src>>des;

    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    memset(prt,-1,sizeof(prt));

    bfs(src);

    int x = des;

    vector<int>vn;
    while(x!=-1)
    {


        vn.push_back(x);
        x = prt[x];
    }

    reverse(vn.begin(),vn.end());

    for(int j: vn)
    {
        cout<<j<<" ";
    }

}


