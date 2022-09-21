#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

struct DSU
{
    int per[N];
    void init(int n)
    {
        iota(per, per + n, 0);
    }
    void join(int a, int b)
    {
        per[b = find(b)] = a = find(a);
    }
    int find(int a)
    {
        return a == per[a] ? a : per[a] = find(per[a]);
    }
    bool isCon(int a, int b)
    {
        return find(a) == find(b);
    }

} tre;

char ans[N];
struct Edge
{
    int f, s, i;
} edg[N];

vector<pair<int, int>> grf[N];

bool vis[N], in[N];

void dfs(int n, int p = 0)
{
    // cout << n << endl;
    in[n] = vis[n] = true;
    for (auto &&i : grf[n])
    {
        if (i.first == p)
        {
            continue;
        }
        if (vis[i.first])
        {
            if (in[i.first] && !tre.isCon(edg[i.second].f, edg[i.second].s))
            {
                tre.join(edg[i.second].f, edg[i.second].s);
                ans[edg[i.second].i] = '0';
                edg[i.second].i = -1;
            }
            continue;
        }
        dfs(i.first, n);
    }
    in[n] = false;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    tre.init(n + 1);
    for (int i = 1; i <= n; i++)
    {
        grf[i].clear();
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &edg[i].f, &edg[i].s);
        edg[i].i = i;
        grf[edg[i].f].push_back({edg[i].s, i});
        grf[edg[i].s].push_back({edg[i].f, i});
    }
    memset(vis + 1, 0, sizeof(vis[0]) * n);
    dfs(1);
    // cout << count(ans, ans + m, '0') << endl;
    for (int i = 0; i < m; i++)
    {
        if (edg[i].i == -1)
        {
            continue;
        }
        if (tre.isCon(edg[i].f, edg[i].s))
        {
            ans[edg[i].i] = '1';
        }
        else
        {
            ans[edg[i].i] = '0';
            tre.join(edg[i].f, edg[i].s);
        }
    }
    assert(count(ans, ans + m, '0') == n - 1);
    ans[m] = '\0';
    printf("%s\n", ans);
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