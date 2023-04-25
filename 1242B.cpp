#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

map<int, int> grf[N];

struct DSU
{
    int per[N], sz[N];
    void init(int n)
    {
        iota(per, per + n, 0);
        fill(sz, sz + n, 1);
    }
    int find(int a)
    {
        return per[a] == a ? a : per[a] = find(per[a]);
    }
    void merge(int a, int b)
    {
        if (grf[b].size() > grf[a].size())
        {
            swap(a, b);
        }
        for (auto &&i : grf[b])
        {
            grf[a][i.first] += i.second;
        }
        sz[a] += sz[b];
        per[find(b)] = find(a);
    }
    bool isCon(int a, int b)
    {
        return find(a) == find(b);
    }
    void prn(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << find(i) << " ";
        }
        cout << endl;
    }
    int calc_sz(int a)
    {
        return sz[find(a)];
    }
} dsu;

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        if (u > v)
        {
            swap(u, v);
        }
        grf[u][v]++;
    }
    dsu.init(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (dsu.calc_sz(i) > 1)
        {
            continue;
        }
        for (int j = i + 1; j <= n; j++)
        {
            if (grf[i][j] < dsu.calc_sz(j))
            {
                dsu.merge(i, j);
                for (auto &&k : grf[j])
                {
                    grf[i][k.first] += k.second;
                }
            }
            // dsu.prn(n + 1);
        }
    }
    set<int> ans;
    for (int i = 1; i <= n; i++)
    {
        ans.insert(dsu.find(i));
    }
    printf("%d\n", (int)ans.size() - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}