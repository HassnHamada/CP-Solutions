#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e3 + 10, M = 1 << 12, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int arr[N];

typedef complex<ll> point;

ll dot(point p1, point p2)
{
    return (conj(p1) * p2).real();
}

ll f(point p, ll x)
{
    return dot(p, {x, 1});
}

point seg[M << 1];
int n, k;

void add(point p, int i = 0, int l = 0, int r = n)
{
    assert(l <= r);
    int m = ((r - l) >> 1) + l;
    bool lVal = f(p, arr[l]) < f(seg[i], arr[l]),
         mVal = f(p, arr[m]) < f(seg[i], arr[m]);
    if (mVal)
    {
        swap(p, seg[i]);
    }
    if (r == l)
    {
        return;
    }
    if (lVal == mVal)
    {
        add(p, 2 * i + 2, m + 1, r);
    }
    else
    {
        add(p, 2 * i + 1, l, m);
    }
}

ll get(int x, int i = 0, int l = 0, int r = n)
{
    int m = ((r - l) >> 1) + l;
    if (r == l)
    {
        return f(seg[i], arr[x]);
    }
    if (x < m)
    {
        return min(f(seg[i], arr[x]), get(x, 2 * i + 1, l, m));
    }
    return min(f(seg[i], arr[x]), get(x, 2 * i + 2, m + 1, r));
}

ll dp[2][N];

void run()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        ll v = arr[n] - arr[i];
        dp[0][i] = v * v;
    }
    for (int i = 1; i < k; i++)
    {
        for (int j = 0; j < (M << 1); j++)
        {

            seg[j] = {0, INT64_MAX >> 1};
        }
        for (int j = n - i; j; j--)
        {
            ll c = dp[(i & 1) ^ 1][j] + 1ll * arr[j] * arr[j],
               m = -2ll * arr[j];
            add({m, c});
            assert(j >= 1);
            dp[i & 1][j - 1] = get(j - 1) + 1ll * arr[j - 1] * arr[j - 1];
        }
    }
    printf("%lld\n", dp[(k & 1) ^ 1][0]);
}

int main()
{
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}