#include <bits/stdc++.h>
using namespace std;

const long long int NK = 1e9 + 5;
const int N = 105;
int hh[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e, q;
    cin >> n >> e;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            hh[i][j] = NK;
            if (i == j) {
                hh[i][j] = 0;
            }
        }
    }

    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        hh[a][b] = min(hh[a][b], c);
        hh[b][a] = min(hh[b][a], c);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (hh[i][k] < NK && hh[k][j] < NK) {
                    hh[i][j] = min(hh[i][j], hh[i][k] + hh[k][j]);
                }
            }
        }
    }

    cin >> q;
    while (q--) {
        int s, g;
        cin >> s >> g;
        if (hh[s][g] == NK) {
            cout << -1 << endl;
        } else {
            cout << hh[s][g] << endl;
        }
    }


}
