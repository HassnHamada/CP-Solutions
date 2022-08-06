#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 10, L = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

// int arr[N];
int n;
ll T[N], acc[N];

// ll ok(ll m)
// {
//     ll t = 0;
//     for (ll i = 1, v = 0; i <= n; i++)
//     {
//         ll r = min(i, m);
//         if (i <= m)
//         {
//             v += t;
//         }
//         if (v >= arr[i])
//         {
//             v -= arr[i];
//         }
//         else
//         {
//             ll w = (arr[i] - v + r - 1) / r;
//             t += w;
//             v = (w * r - arr[i] + v) % r;
//         }
//     }
//     return t;
// }

int solve(int t)
{
    if (T[n] > t)
    {
        return -1;
    }
    int l = 1, h = n;
    while (l < h)
    {
        int m = (h - l) / 2 + l;
        if (T[m] <= t)
        {
            h = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return l;
}

void run()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", acc + i);
        acc[i] += acc[i - 1];
    }
    T[0] = INT64_MAX;
    for (int i = 1, j = 0; i <= n; i++)
    {
        ll l = 1, h = T[i - 1];
        while (l < h)
        {
            ll m = (h - l) / 2 + l;
            if (m * i >= acc[n] && m * j >= acc[j])
            {
                h = m;
            }
            else
            {
                l = m + 1;
            }
        }
        T[i] = l;
        if (j == 0 || (acc[i] + i - 1) / i > (acc[j] + j - 1) / j)
        {
            j = i;
        }
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int t;
        scanf("%d", &t);
        printf("%d\n", solve(t));
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
