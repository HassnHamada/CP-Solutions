#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 4e3 + 10, M = 1e3 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

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

char mat_1[M][M], mat_2[M][M];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", (char *)(mat_1 + i));
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%s", (char *)(mat_2 + i));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a0 = i << 1, a1 = a0 + 1, b0 = (j + n) << 1, b1 = b0 + 1;
            if (mat_1[i][j] == mat_2[i][j])
            {
                // ~a ^ b = (~a | b) & (a | ~b)
                grf[a1].push_back(b1);
                grf[b0].push_back(a0);
                grf[a0].push_back(b0);
                grf[b1].push_back(a1);
            }
            else
            {
                // a ^ b = (a | b) & (~a | ~b)
                grf[a0].push_back(b1);
                grf[b0].push_back(a1);
                grf[a1].push_back(b0);
                grf[b1].push_back(a0);
            }
        }
    }

    printf(ok(n << 1) ? "YES\n" : "NO\n");
    for (int i = 0; i < (n << 2); i++)
    {
        grf[i].clear();
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}