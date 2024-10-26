#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int dp[N];

void preprocess()
{
    // Base case: You start from 1, so dp[1] = true (reachable)
    dp[1] = 1;

    // Build dp array bottom-up
    for(int i = 1; i < N; i++)
    {
        if(dp[i])
        {
            // If you can reach i, you can also reach i + 3 and i * 2
            if(i + 3 < N) dp[i + 3] = 1;
            if(i * 2 < N) dp[i * 2] = 1;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    // Initialize dp array to 0 (unreachable) and preprocess it
    memset(dp, 0, sizeof(dp));
    preprocess();

    while(t--)
    {
        int n;
        cin >> n;

        if(dp[n])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
