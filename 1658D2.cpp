#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 63, L = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll arr[M][L][L];

vector<ll> calc(ll s, ll e)
{
    if (s == 0)
    {
        vector<ll> ret(M);
        for (int i = 0; i < M; i++)
        {
            ret[i] = e / (1ll << (i + 1)) * (1ll << i);
            ret[i] = max(ret[i], ret[i] + e - ret[i] * 2 - (1ll << i));
        }
        return ret;
    }
    vector<ll> a = calc(0, e), b = calc(0, s);
    for (int i = 0; i < M; i++)
    {
        a[i] -= b[i];
        assert(a[i] >= 0);
    }
    return a;
}

// ll l, r, n, mx, mn;
ll l, r, n;
bool solve(int i, ll &ans, vector<ll> &res, vector<ll> &vec)
{
    // cout << i << " " << ans << endl;
    if (i == M)
    {
        // return (arr[i][0][0] == -1 || (arr[i][0][0] ^ ans) <= r) &&
        //        (arr[i][0][1] == -1 || (arr[i][0][1] ^ ans) >= l) &&
        //        (arr[i][1][0] == -1 || (arr[i][1][0] ^ ans) <= r) &&
        //        (arr[i][1][1] == -1 || (arr[i][1][1] ^ ans) >= l);
        // cout << mx << " " << mn << " ";
        // cout << ((mx ^ ans) <= r && (mn ^ ans) >= l) << endl;
        // return (mx ^ ans) <= r && (mn ^ ans) >= l;
        bool ok = true;
        for (int j = 0; ok && j < M; j++)
        {
            ok = (arr[j][0][0] == -1 || (arr[j][0][0] ^ ans) <= r) &&
                 (arr[j][0][1] == -1 || (arr[j][0][1] ^ ans) >= l) &&
                 (arr[j][1][0] == -1 || (arr[j][1][0] ^ ans) <= r) &&
                 (arr[j][1][1] == -1 || (arr[j][1][1] ^ ans) >= l);
        }
        return ok;
    }
    // if (!((arr[i][0][0] == -1 || (arr[i][0][0] ^ ans) <= r) &&
    //       (arr[i][0][1] == -1 || (arr[i][0][1] ^ ans) >= l) &&
    //       (arr[i][1][0] == -1 || (arr[i][1][0] ^ ans) <= r) &&
    //       (arr[i][1][1] == -1 || (arr[i][1][1] ^ ans) >= l)))
    // {
    //     return false;
    // }
    if (res[i] == vec[i] && res[i] == n - vec[i])
    {
        // cout << "AAA\n";
        if (!solve(i + 1, ans, res, vec))
        {
            // cout << "dasdasd\n";
            ans |= 1ll << i;
            // assert(solve(i + 1, ans, res, vec));
            bool ret = solve(i + 1, ans, res, vec);
            if (!ret)
            {
                ans &= ~(1ll << i);
            }
            return ret;
        }
    }
    else if (res[i] == vec[i])
    {
        // cout << "BBB\n";
        // assert(solve(i + 1, ans, res, vec));
        return solve(i + 1, ans, res, vec);
    }
    else if (res[i] == n - vec[i])
    {
        // cout << "CCC\n";
        ans |= 1ll << i;
        // assert(solve(i + 1, ans, res, vec));
        bool ret = solve(i + 1, ans, res, vec);
        if (!ret)
        {
            ans &= ~(1ll << i);
        }
        return ret;
    }
    else
    {
        assert(false);
    }
    return true;
}

void run()
{
    memset(arr, -1, sizeof(arr));
    scanf("%lld%lld", &l, &r);
    auto res = calc(l, r + 1);
    // for (auto &&i : res)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    n = r - l + 1;
    // mx = INT64_MIN, mn = INT64_MAX;
    vector<ll> vec(M);
    for (int i = 0; i < n; i++)
    {
        ll v;
        scanf("%lld", &v);
        for (int j = 0; j < M; j++)
        {
            vec[j] += (v >> j) & 1;
            arr[j][(v >> j) & 1][0] = max(arr[j][(v >> j) & 1][0], v);
            arr[j][(v >> j) & 1][1] = min(arr[j][(v >> j) & 1][1] == -1 ? INT64_MAX : arr[j][(v >> j) & 1][1], v);
        }
        // mx = max(mx, v);
        // mn = min(mn, v);
    }
    // cout << mn << " " << mx << endl;
    // for (auto &&i : res)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (auto &&i : vec)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    ll ans = 0;
    if (!solve(0, ans, res, vec))
    {
        ans = 1;
        assert(solve(0, ans, res, vec));
    }
    // for (int i = M - 1; ~i; i--)
    // for (int i = 0; i < M; i++)
    // {
    //     if (res[i] == vec[i] && res[i] == n - vec[i])
    //     {
    //         if ((arr[i][0][0] == -1 || (arr[i][0][0] ^ ans) <= r) &&
    //             (arr[i][0][1] == -1 || (arr[i][0][1] ^ ans) >= l) &&
    //             (arr[i][1][0] == -1 || (arr[i][1][0] ^ ans) <= r) &&
    //             (arr[i][1][1] == -1 || (arr[i][1][1] ^ ans) >= l))
    //         {
    //             continue;
    //         }
    //         ans |= 1ll << i;
    //         if (!((arr[i][0][0] == -1 || (arr[i][0][0] ^ ans) <= r) &&
    //               (arr[i][0][1] == -1 || (arr[i][0][1] ^ ans) >= l) &&
    //               (arr[i][1][0] == -1 || (arr[i][1][0] ^ ans) <= r) &&
    //               (arr[i][1][1] == -1 || (arr[i][1][1] ^ ans) >= l)))
    //         {
    //             assert(false);
    //         }
    //     }
    //     else if (res[i] == vec[i])
    //     // if (res[i] == vec[i])
    //     {
    //         continue;
    //     }
    //     else if (res[i] == n - vec[i])
    //     {
    //         ans |= 1ll << i;
    //     }
    //     else
    //     {
    //         assert(false);
    //     }
    // }
    printf("%lld\n", ans);
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
