#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
ll arr[N];

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    // int z = __builtin_ctz(n);
    // int p = __builtin_popcount(n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", arr + i);
    }
    if (k >= n)
    {
        ll tot = 1ll * (k - n) * n + 1ll * n * (n - 1) / 2;
        for (int i = 1; i <= n; i++)
        {
            tot += arr[i];
        }
        printf("%lld\n", tot);
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            arr[i] += arr[i - 1];
        }
        ll tot = 0;
        for (int i = k; i <= n; i++)
        {
            tot = max(tot, arr[i] - arr[i - k]);
        }
        tot += 1ll * k * (k - 1) / 2;
        printf("%lld\n", tot);
    }
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
