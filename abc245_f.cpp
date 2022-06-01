#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int n, m, id, ids[N], low[N], cyc[N];
bool onStk[N];
vector<int> grf[N];
stack<int> stk;

void dfs(int c)
{
    low[c] = ids[c] = id++;
    onStk[c] = true;
    stk.push(c);
    for (auto &&i : grf[c])
    {
        if (ids[i] == EMP)
        {
            dfs(i);
        }
        if (onStk[i])
        {
            low[c] = min(low[c], low[i]);
        }
        cyc[c] |= cyc[i];
    }
    if (ids[c] == low[c])
    {
        while (!stk.empty())
        {
            int t = stk.top();
            stk.pop();
            onStk[t] = false;
            low[t] = low[c];
            if (t == c)
            {
                break;
            }
        }
    }
    cyc[c] |= low[c] != ids[c];
}

void tarjan()
{
    for (int i = 1; i <= n; i++)
    {
        ids[i] = EMP;
    }
    for (int i = 1; i <= n; i++)
    {
        if (ids[i] == EMP)
        {
            dfs(i);
        }
    }
}

void run()
{
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        grf[u].push_back(v);
    }
    tarjan();
    printf("%lld\n", count(cyc + 1, cyc + n + 1, 1));
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