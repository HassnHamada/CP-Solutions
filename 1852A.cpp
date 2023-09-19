#include <bits/stdc++.h>
// #include <stdio.h>
// #include <algorithm>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;

int n, k, arr[N];

bool ok(ll sz)
{
    for (int i = 0; i < k; i++)
    {
        sz -= upper_bound(arr, arr + n, sz) - arr;
        if (sz <= 0)
        {
            return false;
        }
    }
    return true;
}

void run()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    ll l = 1, h = 1ll * n * k + 1;
    while (l < h)
    {
        ll m = (h - l) / 2 + l;
        if (ok(m))
        {
            h = m;
        }
        else
        {
            l = m + 1;
        }
    }
    printf("%lld\n", l);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}