#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1e5 + 10, M = 2, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int arr[N], xor_[N], prv[N];
ll sum_[N];

pair<int, int> solve(int l, int r)
{
    int e = r;
    ll w = sum_[r] - sum_[l - 1] - (xor_[r] ^ xor_[l - 1]);
    while (l < r)
    {
        int m = (r - l + 1) / 2 + l;
        ll v = sum_[e] - sum_[m - 1] - (xor_[e] ^ xor_[m - 1]);
        assert(v <= w);
        if (v < w)
        {
            r = m - 1;
        }
        else
        {
            l = m;
        }
    }
    return {l, e};
}

void run()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
        sum_[i] = arr[i] + sum_[i - 1];
        xor_[i] = arr[i] ^ xor_[i - 1];
    }
    memset(prv + 1, 0, sizeof(prv[0]) * n);
    for (int i = n, j = n; i; prv[i--] = j)
    {
        j = min(j, i - 1);
        while (j && arr[j] == 0)
        {
            j--;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        assert(prv[i] == 0 || arr[prv[i]]);
    }
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        if (arr[r] == 0)
        {
            r = max(l, prv[r]);
        }
        ll w = sum_[r] - sum_[l - 1] - (xor_[r] ^ xor_[l - 1]);
        pair<int, int> ans = solve(l, r);
        while (r-- > l)
        {
            if (arr[r] == 0)
            {
                r = max(l, prv[r]);
            }
            ll v = sum_[r] - sum_[l - 1] - (xor_[r] ^ xor_[l - 1]);
            assert(v <= w);
            if (v < w)
            {
                break;
            }
            pair<int, int> tem = solve(l, r);
            if (tem.second - tem.first < ans.second - ans.first)
            {
                ans = tem;
            }
        }
        printf("%d %d\n", ans.first, ans.second);
    }
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