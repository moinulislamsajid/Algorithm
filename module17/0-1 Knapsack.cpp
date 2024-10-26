#include<bits/stdc++.h>
using namespace std;

int Knapsack(int n, int weight[], int value[], int W)
{
    if (n < 0 || W == 0)
    {
        return 0;
    }

    if (weight[n] <= W)
    {
        int opt1 = Knapsack(n - 1, weight, value, W - weight[n]) + value[n];
        int opt2 = Knapsack(n - 1, weight, value, W);

        return max(opt1, opt2); // Compare opt1 and opt2
    }
    else
    {
        return Knapsack(n - 1, weight, value, W);
    }
}

int main()
{
    int n;
    cin >> n;

    int weight[n], value[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int j = 0; j < n; j++)
    {
        cin >> value[j];
    }

    int W;
    cin >> W;

    cout << Knapsack(n - 1, weight, value, W) << endl;
}
