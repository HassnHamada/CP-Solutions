#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 10, M = 128, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int ans[N];

void run()
{
    int n;
    scanf("%d", &n);
    if (n & 1)
    {
        iota(ans, ans + n, (n + 1) / 2 + 2);
        ans[0] -= 1;
        ans[n - 1] += 1;
        ans[n - 2] += 1;
    }
    else
    {
        iota(ans, ans + n / 2, n / 2);
        iota(ans + n / 2, ans + n, n + 1);
    }
    ll mn = INF, mx = -INF, sum = 0;
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", ans[i], " \n"[i + 1 == n]);
        mn = min(mn, (ll)ans[i]);
        mx = max(mx, (ll)ans[i]);
        sum += ans[i];
    }
    assert(mx * mx + mn * mn - 2 * mx * mn == sum);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}