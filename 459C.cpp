#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

bool ok(int n, int d, int k)
{
    int ck = k;
    while (d--)
    {
        if (ck >= n)
        {
            return true;
        }
        ck *= k;
    }
    return false;
}
struct DT
{
    int n, d, l;
};

void solve(int n, int d, int k, bool l = true)
{
    assert(k);
    queue<DT> call;
    call.push({n, d, l});
    while (!call.empty())
    {
        n = call.front().n;
        d = call.front().d;
        l = call.front().l;
        assert(n);
        assert(d);
        call.pop();
        for (int cn = 1, sz = (n + k - 1) / k, b = 1; cn <= n; cn++)
        {
            printf("%d%c", b, " \n"[l && cn == n]);
            if (cn % sz == 0)
            {
                if (b == k)
                {
                    b = 1;
                }
                else
                {
                    b += 1;
                }
            }
        }
        if (d > 1)
        {
            for (int i = 1, sz = (n + k - 1) / k, m = (n + sz - 1) / sz; i <= m; i++)
            {
                if (i == m)
                {
                    call.push({n - sz * (m - 1), d - 1, l});
                }
                else
                {
                    call.push({sz, d - 1, false});
                }
            }
        }
    }
}

void run()
{
    int n, d, k;
    scanf("%d%d%d", &n, &k, &d);
    if (ok(n, d, k))
    {
        solve(n, d, k);
    }
    else
    {
        printf("-1\n");
    }
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