#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 10, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int inp[N], sum[N];

void pre()
{
    for (int i = 1; i < N; i++)
    {
        sum[i] = sum[i - 1] + i;
    }
}

void run()
{
    int m, s, tot = 0, mx = 0;
    scanf("%d%d", &m, &s);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", inp + i);
        tot += inp[i];
        mx = max(mx, inp[i]);
    }
    int n = lower_bound(sum, sum + N, tot + s) - sum;
    assert(n != N);
    printf(sum[n] == s + tot && n >= mx ? "YES\n" : "NO\n");
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    pre();
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
