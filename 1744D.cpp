#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 30, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int n, z = 0;
    scanf("%d", &n);
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        z += __builtin_ctz(v);
    }
    int ans = 0;
    for (int i = M - 1; z < n && i; i--)
    {
        int t = min((n - z + i - 1) / i, n / (1 << i) - n / (1 << (i + 1)));
        ans += t;
        z += t * i;
    }
    printf("%d\n", z >= n ? ans : -1);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
