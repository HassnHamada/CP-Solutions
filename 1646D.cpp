#include <bits/stdc++.h>
using namespace std;
// typedef long long int ll;

const int N = 2e5 + 10;
// int vis[N], vid;
vector<int> tre[N];
map<int, pair<int, int>> dp[N];
bool don[N];

pair<int, int> dfs(int n, int p)
{
    pair<int, int> ret = {1, 0};
    for (auto &&i : tre[n])
    {
        if (i == p)
        {
            continue;
        }
        pair<int, int> res = don[n] ? dfs(i, n) : dp[n][p];
        ret.first += res.second;
        ret.second += res.first;
    }
    return ret;
}

void dfsAns(int n, int p, int t, vector<int> &out)
{
    // printf("in %d %d\n", n, t);
    int tot = 0;
    for (auto &&i : tre[n])
    {
        if (i == p)
        {
            continue;
        }
        dfsAns(i, n, t ^ 1, out);
        tot += out[i - 1];
    }
    out[n - 1] = t ? tot + (p == 0 ? 0 : 1) : 1;
    // printf("out %d\n", n);
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; i++)
    {
        // printf("%d\n", i);
        scanf("%d%d", &u, &v);
        tre[u].push_back(v);
        tre[v].push_back(u);
    }
    pair<int, int> ans = {2, 1};
    for (int i = 1; i <= n; i++)
    {
        pair<int, int> tem = {1, 0};
        for (auto &&j : tre[i])
        {
            dp[i][j] = dfs(j, i);
            tem.first += dp[i][j].second;
            tem.second += dp[i][j].first;
        }
        don[i] = true;
        if (tem.first >= ans.first)
        {
            ans = {tem.first, i};
        }
        // if (tem.second >= ans.first)
        // {
        //     ans = {tem.second, -i};
        // }
    }
    vector<int> out(n);
    dfsAns(abs(ans.second), 0, ans.second > 0 ? 1 : 0, out);
    int sum = 0;
    for (auto &&i : out)
    {
        sum += i;
    }
    printf("%d %d\n", ans.first, sum);
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", out[i], " \n"[i == n - 1]);
    }
}

int main(int argc, char const *argv[])
{
    // freopen("./_input.txt", "r", stdin);
    // freopen("./_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
