#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll arr[N];

int ok(ll m, int n, ll k)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= m)
        {
            continue;
        }
        if (k + arr[i] < m)
        {
            return -1;
        }
        k -= m - arr[i];
    }
    int e = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > m)
        {
            e++;
        }
        else if (k)
        {
            e++;
            k--;
        }
    }
    return e;
}

void run()
{
    ll n, k;
    scanf("%lld%lld", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", arr + i);
    }
    ll l = 1, h = INT64_MAX;
    while (l < h)
    {
        ll m = l + (h - l + 1) / 2;
        int res = ok(m, n, k);
        if (res == -1)
        {
            h = m - 1;
        }
        else
        {
            l = m;
        }
    }
    int res = ok(l, n, k);
    // cerr << l << " " << res << endl;
    assert(res != -1);
    printf("%lld\n", l * n - n + 1 + res);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    freopen("_error.txt", "w", stderr);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}