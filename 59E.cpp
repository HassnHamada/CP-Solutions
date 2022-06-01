#include <bits/stdc++.h>
#define add(a, b, c) (((1ll << 60) - 1) & (((1ll * a) << 40) | ((1ll * b) << 20) | c))
using namespace std;
typedef long long ll;

const int N = 3e3 + 10, M = 20, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
set<int> grf[N];
set<int> dp[N];
bool inq[N][N];
set<ll> fff;

bool prn(int n, int v, int b, int c)
{
    // cout << n << " " << v << endl;
    if (fff.count(add(n, b, c)))
    {
        return false;
    }
    if (!v)
    {
        assert(n == 1);
        return true;
    }
    for (auto &&i : grf[n])
    {
        if (*dp[i].lower_bound(v - 1) == v - 1 && prn(i, v - 1, n, b))
        {
            printf("%d ", i);
            return true;
        }
    }
    // assert(false);
    return false;
}

void run()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        grf[u].insert(v);
        grf[v].insert(u);
    }
    for (int i = 0, a, b, c; i < k; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        fff.insert(add(a, b, c));
    }

    // for (auto &&i : fff)
    // {
    //     cout << i << endl;
    // }
    int ii = 0;
    queue<ll> q;
    q.push(add(0, 0, 1));
    inq[0][0] = true;
    while (q.size())
    {
        queue<ll> t;
        while (q.size())
        {
            ll f = q.front();
            q.pop();
            int b = (int)((f >> 20) & ((1 << 20) - 1)),
                c = (int)(f & ((1 << 20) - 1));
            if (fff.count(f) || inq[b][c])
            {
                continue;
            }
            inq[b][c] = true;
            dp[c].insert(ii);
            for (auto &&i : grf[c])
            {
                t.push(add(b, c, i));
            }
        }
        swap(t, q);
        ii++;
    }
    if (dp[n].size())
    {
        int ans = *dp[n].begin();
        printf("%d\n", ans);
        prn(n, ans, 0, 0);
        printf("%d\n", n);
    }
    else
    {
        printf("-1\n");
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