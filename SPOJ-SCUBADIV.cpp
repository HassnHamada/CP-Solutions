#include <bits/stdc++.h>
// #include <chrono>
// #include "./stdc++.h"
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 1000, M = 100, INF = 0x3f3f3f3f;
int dp[N][M][M], cyl[N][3];

int asd(int n, int t, int a)
{
    // cout << n << " " << t << " " << a << endl;
    if (t == 0 && a == 0)
    {
        return 0;
    }
    if (n == -1)
    {
        return INF;
    }
    if (dp[n][t][a] == -1)
    {
        int x = asd(n - 1, max(t - cyl[n][0], 0), max(a - cyl[n][1], 0)) + cyl[n][2];
        int y = asd(n - 1, t, a);
        dp[n][t][a] = min(x, y);
    }
    return dp[n][t][a];
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);

    int c;
    cin >> c;
    while (c--)
    {
        int t, a, n;
        cin >> t >> a >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> cyl[i][0] >> cyl[i][1] >> cyl[i][2];
        }
        memset(dp, -1, sizeof(dp));
        cout << asd(n - 1, t, a) << endl;
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}
