#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
#include <stdio.h>
#include <string.h>
#endif
using namespace std;
typedef long long ll;

const int N = (int)(3e5 + 10);
int arr[N], frq[N];

// nCr = n!/(r!(n-r)!)
// nC2 = n!/(2!(n-2)!) = n(n-1)(n-2)!/(2!(n-2)!) = n(n-1)/2!
// nC3 = n!/(3!(n-3)!) = n(n-1)(n-2)(n-3)!/(3!(n-3)!) = n(n-1)(n-2)/3!

ll nCr(ll n, ll r)
{
    if (n < r)
    {
        return 0;
    }
    if (n == r || r == 0)
    {
        return 1;
    }
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

ll nC2(ll n)
{
    if (n < 2)
    {
        return 0;
    }
    return n * (n - 1) / 2;
}

ll nC3(ll n)
{
    if (n < 3)
    {
        return 0;
    }
    return n * (n - 1) * (n - 2) / 6;
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        frq[arr[i]]++;
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans += nC3(frq[i]);
        if (i)
        {
            ans += nC2(frq[i]) * frq[i - 1];
            frq[i] += frq[i - 1];
        }
    }
    printf("%lld\n", ans);
    memset(frq, 0, sizeof(frq[0]) * ((unsigned long)(n) + 1));
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