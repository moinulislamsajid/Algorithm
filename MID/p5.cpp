#include<bits/stdc++.h>
using namespace std;
bool vis[100][100];
int dis[100][100];
vector<pair<int,int>> v = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

int r, c;


bool Valid(int i, int j) {
    return (i >= 0 && i < r && j >= 0 && j < c);
}

int bfs(int si, int sj, int ti, int tj) {



    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while (!q.empty()) {
        pair<int,int> pr = q.front();
        int x = pr.first;
        int y = pr.second;
        q.pop();

        if (x == ti && y == tj) {
            return dis[x][y];
        }

        for (int i = 0; i<8; i++) {
            int nx = x + v[i].first;
            int ny = y + v[i].second;

            if (Valid(nx, ny) == true && !vis[nx][ny]) {
                vis[nx][ny] = true;
                dis[nx][ny] = dis[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1;
}

int main() {
    int t;
    cin >> t;

   memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));

    while (t--) {
        cin >> r >> c;

        int si, sj, ti, tj;
        cin >> si >> sj >> ti >> tj;

        if (si == ti && sj == tj) {
            cout << 0 << endl;
        } else {
            int result = bfs(si, sj, ti, tj);
            cout << result << endl;
        }
    }


}
