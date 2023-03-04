#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10, M = 21, L = 30, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int l, r;
    scanf("%d%d", &l, &r);
    int mx = 0;
    for (int i = l; i <= r; i *= 2)
    {
        mx++;
    }
    ll ans = r / (1 << (mx - 1)) - l + 1;
    if (mx >= 2)
    {
        ans = ans + (mx - 1) * max(0ll, r / ((1 << (mx - 2)) * 3) - l + 1ll) % MOD;
    }
    printf("%d %d\n", mx, ans);
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}