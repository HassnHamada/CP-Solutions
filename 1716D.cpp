#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 20, L = 4, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

ll ans[N], prv[N], cur[N];

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    prv[0] = 1;
    set<pair<int, int>> q;
    q.emplace(0, k);
    while (!q.empty())
    {
        auto f = *q.begin();
        q.erase(q.begin());
        int cn = f.first;
        int ck = f.second;
        for (int i = cn + ck; i <= n; i += ck)
        {
            cur[i] = (cur[i] + prv[cn]) % MOD;
            q.emplace(i, ck + 1);
        }
        if (q.empty() || (q.begin()->second) == ck + 1)
        {
            for (int i = 1; i <= n; i++)
            {
                ans[i] = (ans[i] + cur[i]) % MOD;
            }
            swap(cur, prv);
            memset(cur, 0, sizeof(cur[0]) * (n + 1));
            for (int i = 1; i <= n; i++)
            {
                std::printf("%lld%c", ans[i], " \n"[i == n]);
            }
        }

    }

    for (int i = 1; i <= n; i++)
    {
        std::printf("%lld%c", ans[i], " \n"[i == n]);
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
