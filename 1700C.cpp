#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 10, L = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll arr[N];
int n;

ll calc()
{
    ll ret = abs(arr[0]);
    for (ll i = 1, v = max(-arr[0], 0ll); i < n; i++)
    {
        ll w = arr[i] + v;
        ret += abs(w) * (w < 0 ? 2 : 1);
        v -= w;
    }
    return ret;
}

void run()
{
    ll mn = INT64_MAX;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", arr + i);
        mn = min(mn, arr[i]);
    }
    if (mn > 0)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] -= mn;
        }
    }
    ll ans = calc();
    reverse(arr, arr + n);
    ans = min(ans, calc());
    printf("%lld\n", ans + max(mn, 0ll));
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
