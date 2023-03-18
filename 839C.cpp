#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 1e6 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> tre[N];

double dfs(int cn = 1, int pn = 0, int d = 0, double p = 1)
{
    int sz = tre[cn].size() - (pn == 0 ? 0 : 1);
    if (sz == 0)
    {
        return d * p;
    }
    double ret = 0;
    for (auto &&i : tre[cn])
    {
        if (i == pn)
        {
            continue;
        }
        ret += dfs(i, cn, d + 1, p / sz);
    }
    return ret;
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        tre[u].push_back(v);
        tre[v].push_back(u);
    }
    printf("%.15lf\n", dfs());
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