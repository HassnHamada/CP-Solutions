#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2e2 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int ans[N];
deque<int> grf[N >> 1];
pair<int, int> edg[N];
bool usd[N];

bool dfs(int cn, int cm)
{
    // cout << cn << " " << cm << endl;
    ans[cm] = cn;
    if (cm == 0)
    {
        return cn == 1;
    }
    int sz = grf[cn].size();
    for (int i = 0; i < sz; i++)
    {
        int v = grf[cn].back();
        grf[cn].pop_back();
        if (!usd[v])
        {
            usd[v] = true;
            if (dfs(edg[v].first == cn ? edg[v].second : edg[v].first, cm - 1))
            {
                return true;
            }
            usd[v] = false;
        }
        grf[cn].push_front(v);
    }
    return false;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        grf[u].push_back(i);
        grf[v].push_back(i);
        edg[i] = {u, v};
    }
    if (dfs(1, m))
    {
        for (int i = 0; i <= m; i++)
        {
            printf("%d%c", ans[i], " \n"[i == m]);
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