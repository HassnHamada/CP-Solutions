#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 1 << 12, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

set<int> grf[N];

struct DSU
{
    int sz;
    vector<int> per;
    void init(int n)
    {
        per.resize(sz = n);
        iota(per.begin(), per.end(), 0);
    }
    void join(int a, int b)
    {
        b = find(b);
        a = find(a);
        if (a > b)
        {
            swap(a, b);
        }
        if (!isCon(a, b))
        {
            sz--;
            per[b] = a;
            // per[b] = per[a];
        }
    }
    void split(int a, int b)
    {
        if (a > b)
        {
            swap(a, b);
        }
        grf[a].erase(b);
        grf[b].erase(a);
        per[a] = a;
        per[b] = b;
        sz += 2;
        if (!grf[a].empty())
        {
            join(a, *grf[a].begin());
        }
        if (!grf[b].empty())
        {
            join(b, *grf[b].begin());
        }
    }
    int find(int a)
    {
        return a == per[a] ? a : per[a] = find(per[a]);
        // return a == per[a] ? a : find(per[a]);
    }
    bool isCon(int a, int b)
    {
        return find(a) == find(b);
    }
    void prn()
    {
        cout << sz << "\n";
        for (auto &&i : per)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    // int sz()
    // {
    //     return set<int>(per.begin(), per.end()).size();
    // }
} dsu;

int ans[N];

void run()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    dsu.init(n + 1);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        grf[u].insert(v);
        grf[v].insert(u);
        if (!dsu.isCon(u, v))
        {
            dsu.join(u, v);
        }
        dsu.prn();
    }
    ans[0] = dsu.sz;
    for (int i = 1, t, u, v; i <= k; i++)
    {
        scanf("%d%d%d", &t, &u, &v);
        if (t & 1)
        {
            grf[u].insert(v);
            grf[v].insert(u);
            if (!dsu.isCon(u, v))
            {
                dsu.join(u, v);
            }
        }
        else
        {
            assert(dsu.isCon(u, v));
            dsu.split(u, v);
        }
        dsu.prn();
        ans[i] = dsu.sz;
    }
    for (int i = 0; i <= k; i++)
    {
        printf("%d%c", ans[i] - 1, " \n"[i == k]);
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