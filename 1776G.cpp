#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

const int N = 2e6 + 10, M = 1e6 + 10, Q = 548, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char inp[N];
int acc[N], nxt[N];

ll calc_n2(int tar, int n)
{
    // cout << "O(n2) target: " << tar << endl;
    ll ret = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + n; j <= 2 * n - 1; j++)
        {
            ret += (acc[j] - acc[i]) == tar;
        }
    }
    // cout << "O(n2) return: " << ret << endl;
    return ret;
}

ll calc_nlogn(int tar, int n)
{
    // cout << "target: " << tar << endl;
    ll ret = 0;
    for (int i = 0; i < n; i++)
    {
        int l = lower_bound(acc + i + n, acc + 2 * n, tar + acc[i]) - acc,
            h = upper_bound(acc + i + n, acc + 2 * n, tar + acc[i]) - acc;
        ret += max(0, h - l);
    }
    // cout << "return: " << ret << endl;
    return ret;
}

ll calc_n(int tar, int n)
{
    // cout << "O(n) target: " << tar << endl;
    ll ret = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        j = max(j, i + n);
        while (j < 2 * n && acc[j] - acc[i] < tar)
        {
            j = nxt[j];
        }
        if (j == 2 * n)
        {
            break;
        }
        if (acc[j] - acc[i] == tar)
        {
            ret += nxt[j] - j;
        }
    }
    // cout << "O(n) return: " << ret << endl;
    return ret;
}

void run()
{
    int n;
    scanf("%d%s", &n, inp + 1);
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        acc[i] = acc[i - 1] + (inp[i] == 'W');
    }
    for (int i = 0; i <= 2 * n - 1; i++)
    {
        nxt[i] = lower_bound(acc + i + 1, acc + 2 * n, acc[i] + 1) - acc;
    }
    int l = 0, sz = 2 * n - 1;
    while (sz)
    {
        // cout << l << " " << sz << endl;
        int m1 = l + sz / 3,
            m2 = l + sz - sz / 3;
        ll v1 = calc_n(m1, n), v2 = calc_n(m2, n);
        // cout << "(" << m1 << ", " << v1 << ") (" << m2 << ", " << v2 << ")" << endl;
        // assert(v1 == calc_n2(m1, n));
        // assert(v2 == calc_n2(m2, n));
        if (v2 > v1)
        {
            l = m1 + 1;
        }
        sz -= sz / 3 + 1;
    }
    printf("%d\n", l);
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
