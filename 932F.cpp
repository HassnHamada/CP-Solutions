#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int aaa[N], bbb[N], ppp[N];
vector<int> tre[N], lev;
bool is_lev[N];
ll ans[N];

void dfs(int n = 1, int p = 0)
{
    ppp[n] = p;
    is_lev[n] = true;
    for (auto &&i : tre[n])
    {
        if (i == p)
        {
            continue;
        }
        dfs(i, n);
        is_lev[n] = false;
    }
    if (is_lev[n])
    {
        lev.push_back(n);
    }
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", aaa + i);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", bbb + i);
    }
    for (int i = 0, u, v; i < n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        tre[u].push_back(v);
        tre[v].push_back(u);
    }
    dfs();
    memset(ans, 0x3f, sizeof(ans));
    while (!lev.empty())
    {
        // cout << lev.size() << endl;
        set<int> tem;
        for (auto &&i : lev)
        {
            // cout << i << " -------- ";
            if (ppp[i])
            {
                tem.insert(ppp[i]);
            }
            assert(!tre[i].empty());
            if (is_lev[i])
            {
                ans[i] = 0;
                continue;
            }
            for (auto &&j : tre[i])
            {
                if (j == ppp[i])
                {
                    continue;
                }
                // cout << j << " ";
                ans[i] = min(ans[i], 1ll * aaa[i] * bbb[j] + ans[j]);
            }
        }
        // cout << endl;
        lev.clear();
        lev.insert(lev.end(), tem.begin(), tem.end());
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld%c", ans[i], " \n"[i == n]);
    }
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