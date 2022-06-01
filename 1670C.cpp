#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 2e2 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int aaa[N], bbb[N], ddd[N], tak[N];

struct DSU
{
    int n, per[N], sz[N];
    // int n, per[N], rnk[N], sz[N];
    void init(int n)
    {
        this->n = n;
        iota(per, per + n, 0);
        // memset(rnk, 0, sizeof(rnk[0]) * n);
        for (int i = 0; i < n; i++)
        {
            sz[i] = 1;
        }
    }
    int find(int a)
    {
        return a == per[a] ? a : per[a] = find(per[a]);
    }
    bool isCon(int a, int b)
    {
        return find(a) == find(b);
    }
    void join(int a, int b)
    {
        if (isCon(a, b))
        {
            return;
        }
        n -= 1;
        a = find(a), b = find(b);
        if (sz[a] > sz[b])
        {
            per[b] = a;
            sz[a] += sz[b];
        }
        else
        {
            per[a] = b;
            sz[b] += sz[a];
        }
        // per[b = find(b)] = a = find(a);
    }
} sss;

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", aaa + i);
        aaa[i] -= 1;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", bbb + i);
        bbb[i] -= 1;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", ddd + i);
        ddd[i] -= 1;
    }
    sss.init(n);
    for (int i = 0; i < n; i++)
    {
        sss.join(aaa[i], bbb[i]);
    }
    set<int> tem;
    for (int i = 0; i < n; i++)
    {
        tem.insert(sss.find(i));
    }
    // cout << tem.size() << endl;
    for (int i = 0; i < n; i++)
    {
        if (ddd[i] == -1)
        {
            continue;
        }
        tem.erase(sss.find(ddd[i]));
    }
    // cout << tem.size() << endl;
    int p = 0;
    for (auto &&i : tem)
    {
        if (sss.sz[i] > 1)
        {
            p += 1;
        }
    }
    ll ans = 1;
    for (int i = 0; i < p; i++)
    {
        ans = ans * 2 % MOD;
    }
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