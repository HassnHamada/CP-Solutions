#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e2 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int rrr[N], ggg[N], bbb[N], dp[N][N][N];

int solve(int r, int g, int b)
{
    // fprintf(stderr, "r: %d, g: %d, b: %d\n", r, g, b);
    assert(r >= 0 && r < N);
    assert(g >= 0 && g < N);
    assert(b >= 0 && b < N);
    int u = r ? rrr[r - 1] : 0,
        v = g ? ggg[g - 1] : 0,
        w = b ? bbb[b - 1] : 0;
    if (dp[r][g][b] == -1)
    {
        dp[r][g][b] = max({u && v ? u * v + solve(r - 1, g - 1, b) : 0,
                           u && w ? u * w + solve(r - 1, g, b - 1) : 0,
                           v && w ? v * w + solve(r, g - 1, b - 1) : 0});
    }
    // fprintf(stderr, "Out: %d\n", dp[r][g][b]);
    return dp[r][g][b];
}

void run()
{
    int r, g, b;
    scanf("%d%d%d", &r, &g, &b);
    for (int i = 0; i < r; i++)
    {
        scanf("%d", rrr + i);
    }
    for (int i = 0; i < g; i++)
    {
        scanf("%d", ggg + i);
    }
    for (int i = 0; i < b; i++)
    {
        scanf("%d", bbb + i);
    }
    sort(rrr, rrr + r);
    sort(ggg, ggg + g);
    sort(bbb, bbb + b);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(r, g, b));
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