#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5 + 10, M = 2, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int per[N], deg[N], sz[N];

int find(int a)
{
    return a == per[a] ? a : per[a] = find(per[a]);
}
void join(int a, int b)
{
    per[b = find(b)] = a = find(a);
    sz[a] += sz[b];
    deg[a] += deg[b];
}
bool isCon(int a, int b)
{
    return find(a) == find(b);
}

int val[N], ans[N];
set<pair<int, int>> sss;

void run()
{
    int n;
    scanf("%d", &n);
    iota(per, per + n, 0);
    fill(sz, sz + n, 1);
    fill(ans, ans + n, 0);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", deg + i);
        sss.insert({val[i] = deg[i] - 1, i});
    }
    int c = 1;
    while (!sss.empty())
    {
        auto it = *sss.begin();
        sss.erase(sss.begin());
        int w = find(it.second);
        if (it.first != val[w])
        {
            sss.insert({val[w], it.second});
            continue;
        }
        if (it.first <= 0)
        {
            if (ans[w] == 0)
            {
                ans[w] = c++;
            }
            ans[it.second] = ans[w];
        }
        else
        {
            printf("? %d\n", it.second + 1);
            fflush(stdout);
            int v;
            scanf("%d", &v);
            if (v-- == -1)
            {
                sss.insert(it);
                continue;
            }
            v = find(v);
            if (isCon(v, w) || val[w] < deg[v] + deg[w] - (sz[v] + sz[w]) * (sz[v] + sz[w]))
            {
                sss.insert(it);
                continue;
            }
            join(v, w);
            sss.insert({val[v] = deg[v] - sz[v] * sz[v], it.second});
        }
    }
    printf("!");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", ans[i]);
    }
    printf("\n");
    fflush(stdout);
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