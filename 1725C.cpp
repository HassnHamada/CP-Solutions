#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 10, M = 3, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

ll arr[N];

ll my_pow(ll b, ll p, ll m)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
        {
            r = r * b % m;
        }
        b = b * b % m;
        p = p / 2;
    }
    return r;
}

void run()
{
    ll n, m;
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", arr + i);
        arr[i] += arr[i - 1];
    }
    if (n == 1 || arr[n] % 4)
    {
        printf("%lld", my_pow(m, n, MOD));
    }
    else
    {
        int s = 0, l = 0;
        for (int i = 1; i <= n; i++)
        {
            int p1 = lower_bound(arr, arr + n + 1, (arr[i - 1] + arr[n] / 4) % arr[n]) - arr,
                p2 = lower_bound(arr, arr + n + 1, (arr[i - 1] + arr[n] / 4 * 2) % arr[n]) - arr,
                p3 = lower_bound(arr, arr + n + 1, (arr[i - 1] + arr[n] / 4 * 3) % arr[n]) - arr;
            if ((p1 <= n && arr[p1] == (arr[i - 1] + arr[n] / 4) % arr[n]) &&
                (p2 <= n && arr[p2] == (arr[i - 1] + arr[n] / 4 * 2) % arr[n]) &&
                (p3 <= n && arr[p3] == (arr[i - 1] + arr[n] / 4 * 3) % arr[n]))
            {
                s += 1;
            }
            else if (p2 <= n && arr[p2] == (arr[i - 1] + arr[n] / 4 * 2) % arr[n])
            {
                l += 1;
            }
        }
        assert(l % 2 == 0);
        assert(s % 4 == 0);
        ll vl = (m * my_pow(m-1, n-2, MOD) + m * (m - 1) * my_pow(m, n-2, MOD)) % MOD,
           vs = (my_pow(m, 4, MOD) - 4 * m * (m - 1) % MOD - m % MOD + 2 * MOD) % MOD * s / 4,
           vp = my_pow(m, n - l - s, MOD);
        cout << vl << " " << vs << " " << vp << endl;
        printf("%lld\n", vl * vs % MOD * vp % MOD);
        // printf("%lld", vt * vp % MOD);
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}