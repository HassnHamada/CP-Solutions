#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 1e6 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> tre[N];
int par[N], ch[N];

int dfs(int n = 1, int p = 0, int x1 = 0, int x2 = 0)
{
    int ans = ch[n] = par[n] ^ x1;
    for (auto &&i : tre[n])
    {
        if (i == p)
        {
            continue;
        }
        ans += dfs(i, n, x2, par[n]);
    }
    //  x   y   r
    //  0   0   0
    //  0   1   1
    //  1   0   0
    //  1   1   1
    return ans;
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
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", par + i);
    }
    for (int i = 1, v; i <= n; i++)
    {
        scanf("%d", &v);
        par[i] ^= v;
    }
    printf("%d\n", dfs());
    for (int i = 1; i <= n; i++)
    {
        if (ch[i])
        {
            printf("%d\n", i);
        }
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}