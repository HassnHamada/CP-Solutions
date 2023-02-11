#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e3 + 10, M = 1e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int arr[N];

ll my_pow(ll b, ll p, ll m = MOD)
{
    b %= m;
    p %= (m - 1);
    ll r = 1;
    while (p)
    {
        if (p & 1)
        {
            r = r * b % m;
        }
        p /= 2;
        b = b * b % m;
    }
    return r;
}

void run()
{
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int l = lower_bound(arr, arr + n, 2 * arr[i] - arr[j]) - arr,
                r = lower_bound(arr, arr + n, 2 * arr[j] - arr[i]) - arr;
            // cout << i << " " << j << " " << l << " " << n - r << endl;
            ans = (ans + my_pow(2, l + n - r)) % MOD;
        }
        // cout << ans << endl;
    }
    printf("%lld\n", ans);
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
