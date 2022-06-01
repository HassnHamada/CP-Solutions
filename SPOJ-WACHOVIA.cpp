#include <bits/stdc++.h>
// #include <chrono>
// #include "./stdc++.h"
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 1001, M = 50;
int dp[M][N];
pair<int, int> bgs[M];

int asd(int k, int m)
{
    if (k == -1)
    {
        return 0;
    }
    if (dp[k][m] == -1)
    {
        if (bgs[k].first <= m)
        {
            int a = asd(k - 1, m - bgs[k].first) + bgs[k].second;
            int b = asd(k - 1, m);
            dp[k][m] = max(a, b);
        }
        else
        {
            dp[k][m] = asd(k - 1, m);
        }
    }
    return dp[k][m];
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);

    int n;
    cin >> n;
    while (n--)
    {
        int k, m;
        cin >> k >> m;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < m; i++)
        {
            cin >> bgs[i].first >> bgs[i].second;
        }
        printf("Hey stupid robber, you can get %d.\n", asd(m - 1, k));
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}
