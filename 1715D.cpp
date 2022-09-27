#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> grf[N << 1];
int ids[N << 1], low[N << 1], cyc[N << 1], id, cid;
bool onStk[N << 1];
stack<int> stk;

void dfs(int c)
{
    low[c] = ids[c] = id++;
    onStk[c] = true;
    stk.push(c);
    for (auto &&i : grf[c])
    {
        if (ids[i] == -1)
        {
            dfs(i);
        }
        if (onStk[i])
        {
            low[c] = min(low[c], low[i]);
        }
    }
    if (ids[c] == low[c])
    {
        cyc[c] = ++cid;
        while (!stk.empty())
        {
            int t = stk.top();
            stk.pop();
            onStk[t] = false;
            cyc[t] = cyc[c];
            low[t] = low[c];
            if (t == c)
            {
                break;
            }
        }
    }
}

bool ok(int n)
{
    memset(ids, -1, sizeof(ids[0]) * n << 1);
    for (int i = 0; i < (n << 1); i++)
    {
        if (ids[i] == -1)
        {
            dfs(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (cyc[i << 1] == cyc[(i << 1) + 1])
        {
            return false;
        }
    }
    return true;
}

int qqq[N << 1][3], ans[N];

void run()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int qi = 0, u, v, x; qi < q; qi++)
    {
        scanf("%d%d%d", &u, &v, &x);
        qqq[qi][0] = u - 1;
        qqq[qi][1] = v - 1;
        qqq[qi][2] = x;
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < q; j++)
        {
            int u = qqq[j][0], v = qqq[j][1], x = qqq[j][2];
            if (x & (1 << i))
            {
                grf[u << 1].push_back((v << 1) + 1);
                if (u != v)
                {
                    grf[v << 1].push_back((u << 1) + 1);
                }
            }
            else
            {
                grf[(u << 1) + 1].push_back(u << 1);
                if (u != v)
                {
                    grf[(v << 1) + 1].push_back(v << 1);
                }
            }
        }
        assert(ok(n));
        for (int j = 0; j < n; j++)
        {
            ans[j] |= (cyc[j << 1] > cyc[(j << 1) + 1]) << i;
        }
        for (int j = 0; j < n; j++)
        {
            if (ans[j] & (1 << i))
            {
                bool ok = true;
                for (auto &&k : grf[j << 1])
                {
                    if ((k >> 1) == j)
                    {
                        ok = false;
                    }
                    else if (k & 1)
                    {
                        ok = ans[k >> 1] & (1 << i);
                    }
                    if (!ok)
                    {
                        break;
                    }
                }
                if (ok)
                {
                    ans[j] ^= (1 << i);
                }
            }
        }
        for (int j = 0; j < n; j++)
        {
            grf[j << 1].clear();
            grf[(j << 1) + 1].clear();
        }
    }
    for (int i = 0; i < q; i++)
    {
        assert((ans[qqq[i][0]] | ans[qqq[i][1]]) == qqq[i][2]);
        // if ((ans[qqq[i][0]] | ans[qqq[i][1]]) != qqq[i][2])
        // {
        //     cout << qqq[i][0] << " " << qqq[i][1] << " " << qqq[i][2] << endl;
        //     assert(false);
        // }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", ans[i], " \n"[i + 1 == n]);
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}