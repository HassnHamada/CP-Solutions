#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 26, L = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll arr[N];

void run()
{
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", arr + i);
    }
    sort(arr, arr + n + 1);
    for (int i = 1; i <= n; i++)
    {
        arr[i] += arr[i - 1];
    }
    ll ans = 0, d = 0;
    while (n)
    {
        while (arr[n] + d * n > x)
        {
            n -= 1;
        }
        if (n)
        {
            int v = (x - arr[n]) / n;
            ans += (ll)(n) * (v - d + 1);
            d = v + 1;
        }
    }
    printf("%lld\n", ans);
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
