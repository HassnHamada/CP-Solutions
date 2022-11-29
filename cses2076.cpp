#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

vector<int> grf[N];
int lvl[N], cnt[N];
vector<tuple<int, int>> ans;

void dfs(int n, int p = 0)
{
    lvl[n] = lvl[p] + 1;
    for (auto &&i : grf[n])
    {
        if (i == p)
        {
            continue;
        }
        if (lvl[i])
        {
            assert(lvl[i] != lvl[n]);
            if (lvl[i] < lvl[n])
            {
                cnt[n]++;
            }
            else
            {
                cnt[n]--;
            }
        }
        else
        {
            dfs(i, n);
            cnt[n] += cnt[i];
        }
    }
    if (p && cnt[n] == 0)
    {
        ans.emplace_back(p, n);
    }
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        grf[u].push_back(v);
        grf[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!lvl[i])
        {
            dfs(i);
            assert(cnt[i] == 0);
        }
    }
    printf("%d\n", (int)ans.size());
    for (auto &&[i, j] : ans)
    {
        printf("%d %d\n", i, j);
    }
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}