#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#endif
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;
int arr[N], n, x;

bool ok(ll m)
{
    ll tot = 0;
    for (int i = 0; i < n; i++)
    {
        tot += min((ll)arr[i], m);
    }
    return tot + x >= m * n;
}

void run()
{
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    ll ans = 0;
    for (int i = 30; ~i; i--)
    {
        if (ok(ans | (1 << i)))
        {
            ans |= 1 << i;
        }
    }

    printf("%lld\n", ans);
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