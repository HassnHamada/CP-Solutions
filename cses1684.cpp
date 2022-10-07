#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> grf[N];
int ids[N], low[N], cyc[N], id, cid;
bool onStk[N];
stack<int> stk;

void dfs(int c)
{
    ids[c] = low[c] = id++;
    stk.push(c);
    onStk[c] = true;
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
        cyc[c] = cid++;
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
    memset(ids, -1, sizeof(ids[0]) * (n << 1));
    memset(ids, -1, sizeof(ids[0]) * (n << 1));
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

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        char c1, c2;
        int d1, d2;
        scanf("\n%c %d %c %d", &c1, &d1, &c2, &d2);
        int a = ((d1 - 1) << 1) + (c1 == '+'), b = ((d2 - 1) << 1) + (c2 == '+');
        grf[a ^ 1].push_back(b);
        grf[b ^ 1].push_back(a);
    }
    if (ok(m))
    {
        for (int i = 0; i < m; i++)
        {
            printf("%c%c", cyc[(i << 1) + 1] < cyc[i << 1] ? '+' : '-', " \n"[i + 1 == m]);
        }
    }
    else
    {
        printf("IMPOSSIBLE\n");
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