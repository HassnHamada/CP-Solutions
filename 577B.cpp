#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10, M = 1e3 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], frq[M];
bool dp[M][M];

bool solve(int i, int v, int m, bool e)
{
    fprintf(stderr, "i: %d, v: %d, m: %d, e: %d\n", i, v, m, e);
    if (!e && v == 0)
    {
        return true;
    }
    if (i == m || dp[i][v])
    {
        return false;
    }
    dp[i][v] = true;
    for (int j = 0; j <= min(frq[i], m); j++)
    {
        if (solve(i + 1, (v + j * i) % m, m, e && j == 0))
        {
            return true;
        }
    }
    return false;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        frq[arr[i] % m]++;
    }
    printf(solve(0, 0, m, true) ? "YES\n" : "NO\n");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}