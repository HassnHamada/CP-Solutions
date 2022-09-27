#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e4 + 10, M = 1e2 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

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

int mat[M][M], ans[M][M];

void fill_grf(int i_1, int j_1, int i_2, int j_2, int m)
{
    int a0 = (i_1 * m + j_1) << 1, a1 = a0 + 1,
        b0 = (i_2 * m + j_2) << 1, b1 = b0 + 1;
    if (mat[i_1][j_1] == mat[i_2][j_2])
    {
        grf[a0].push_back(b1);
        grf[b0].push_back(a1);
        grf[a1].push_back(b0);
        grf[b1].push_back(a0);
    }
    else
    {
        grf[a0].push_back(a0);
        grf[a1].push_back(a1);
        grf[b0].push_back(b0);
        grf[b1].push_back(b1);
        if (mat[i_1][j_1] + 1 == mat[i_2][j_2])
        {
            grf[a1].push_back(b1);
            grf[b0].push_back(a0);
        }
        else if (mat[i_1][j_1] == mat[i_2][j_2] + 1)
        {
            grf[a0].push_back(b0);
            grf[b1].push_back(a1);
        }
    }
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", (int *)(mat + i) + j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i + 1 < n)
            {
                fill_grf(i, j, i + 1, j, m);
            }
            if (j + 1 < m)
            {
                fill_grf(i, j, i, j + 1, m);
            }
        }
    }
    assert(ok(n * m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans[i][j] = mat[i][j] + (cyc[((i * m + j) << 1) + 1] < cyc[(i * m + j) << 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            assert(abs(ans[i][j] - mat[i][j]) <= 1);
            if (i + 1 < n)
            {
                assert(abs(ans[i][j] - ans[i + 1][j]) >= 1);
            }
            if (j + 1 < m)
            {
                assert(abs(ans[i][j] - ans[i][j + 1]) >= 1);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d%c", ans[i][j], " \n"[j + 1 == m]);
        }
    }
    for (int i = 0; i < (n * m << 1); i++)
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