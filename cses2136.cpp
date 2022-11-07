#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// #pragma GCC optimize("-Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-funroll-loops")
// #pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

const int N = 2e4 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int inp[N];
char buf[M];

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", buf);
        for (int j = 0; j < k; j++)
        {
            inp[i] = (inp[i] << 1) + (buf[j] == '1');
        }
    }
    int ans = k;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans = min(ans, __builtin_popcount(inp[i] ^ inp[j]));
        }
    }
    printf("%d\n", ans);
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}