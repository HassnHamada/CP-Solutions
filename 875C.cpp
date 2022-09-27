#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> grf[N];
int ids[N], low[N], cyc[N], id, cid;
bool onStk[N];
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
    if (low[c] == ids[c])
    {
        cyc[c] = cid++;
        while (true)
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

vector<int> inp[N >> 1];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, l; i < n; i++)
    {
        scanf("%d", &l);
        inp[i].resize(l);
        for (auto &&j : inp[i])
        {
            scanf("%d", &j);
            j -= 1;
        }
    }
    bool _ok = true;
    for (int i = 0; _ok && i < n - 1; i++)
    {
        for (int j = 0, l = inp[i].size(); j < l; j++)
        {
            if (j == (int)inp[i + 1].size())
            {
                _ok = false;
                break;
            }
            if (inp[i][j] == inp[i + 1][j])
            {
                continue;
            }
            if (inp[i][j] > inp[i + 1][j])
            {
                // (a | a) & (~b | ~b)
                grf[inp[i][j] << 1].push_back((inp[i][j] << 1) + 1);
                grf[(inp[i + 1][j] << 1) + 1].push_back(inp[i + 1][j] << 1);
            }
            if (inp[i][j] < inp[i + 1][j])
            {
                // (a | ~b)
                grf[inp[i][j] << 1].push_back(inp[i + 1][j] << 1);
                grf[(inp[i + 1][j] << 1) + 1].push_back((inp[i][j] << 1) + 1);
            }
            break;
        }
    }
    if (_ok && ok(m))
    {
        printf("Yes\n");
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            if (cyc[(i << 1) + 1] < cyc[i << 1])
            {
                ans.push_back(i + 1);
            }
        }
        printf("%d\n", (int)ans.size());
        for (int i = 0, j = ans.size(); i < j; i++)
        {
            printf("%d%c", ans[i], " \n"[i + 1 == j]);
        }
    }
    else
    {
        printf("No\n");
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