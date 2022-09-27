#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 20, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

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
    memset(ids, -1, sizeof(ids[0]) * n);
    for (int i = 0; i < n; i++)
    {
        if (ids[i] == -1)
        {
            dfs(i);
        }
    }
    set<int> usd;
    for (int i = 0; i < n; i++)
    {
        if (usd.find(cyc[i]) != usd.end())
        {
            return false;
        }
        usd.insert(cyc[i]);
    }
    return true;
}

int dir[N], vis[N], vid = 1;

bool dfs_2(int n)
{
    vis[n] = vid;
    for (auto &&i : grf[n])
    {
        if (dir[i] == dir[n])
        {
            return false;
        }
        dir[i] = dir[n] ^ 1;
    }
    for (auto &&i : grf[n])
    {
        if (vis[i] == vid)
        {
            continue;
        }
        if (!dfs_2(i))
        {
            return false;
        }
    }
    return true;
}

struct
{
    int a, b, c;
} inp[N];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &inp[i].a, &inp[i].b, &inp[i].c);
        grf[--inp[i].b].push_back(--inp[i].c);
        grf[inp[i].c].push_back(inp[i].b);
    }
    memset(dir, -1, sizeof(dir));
    // 0 = L, 1 = R
    bool _ok = true;
    for (int i = 0; _ok && i < n; i++)
    {
        if (dir[i] == -1)
        {
            dir[i] = 0;
            _ok = dfs_2(i);
        }
    }
    if (_ok)
    {
        for (int i = 0; i < n; i++)
        {
            grf[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            assert(dir[inp[i].b] == 0 || dir[inp[i].b] == 1);
            assert(dir[inp[i].c] == 0 || dir[inp[i].c] == 1);
            assert(dir[inp[i].b] ^ dir[inp[i].c]);
            if (inp[i].a == 1)
            {
                if (dir[inp[i].b])
                {
                    grf[inp[i].b].push_back(inp[i].c);
                }
                else
                {
                    grf[inp[i].c].push_back(inp[i].b);
                }
            }
            else if (inp[i].a == 2)
            {
                if (dir[inp[i].b])
                {
                    grf[inp[i].c].push_back(inp[i].b);
                }
                else
                {
                    grf[inp[i].b].push_back(inp[i].c);
                }
            }
            else
            {
                assert(false);
            }
        }
    }
    if (_ok && ok(n))
    {
        printf("YES\n");
        for (int i = 0; i < m; i++)
        {
            if (inp[i].a == 1)
            {
                if (dir[inp[i].b])
                {
                    assert(cyc[inp[i].b] > cyc[inp[i].c]);
                }
                else
                {
                    assert(cyc[inp[i].b] < cyc[inp[i].c]);
                }
            }
            else
            {
                if (dir[inp[i].b])
                {
                    assert(cyc[inp[i].b] < cyc[inp[i].c]);
                }
                else
                {
                    assert(cyc[inp[i].b] > cyc[inp[i].c]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("%c %d\n", "LR"[dir[i]], cyc[i]);
        }
    }
    else
    {
        printf("NO\n");
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