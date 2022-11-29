#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e4 + 10, M = 1e2 + 10, MOD = 1e9, HV = 151, INF = 0x3f3f3f3f;

char buf[M];

struct DT
{
    string name;
    int cost = 0, prst = 0;
    DT(string name_, int cost_ = 0, int prst_ = 0)
        : name(name_), cost(cost_), prst(prst_) {}
};

vector<string> inp;
map<string, vector<DT>> grf;
map<string, pair<int, int>> mem;
vector<int> dp, ans;

pair<int, int> dfs(string s)
{
    if (mem.find(s) == mem.end())
    {
        pair<int, int> ret = {INF, 0};
        for (auto &&i : grf[s])
        {
            auto res = dfs(i.name);
            res = {res.first + i.cost, res.second + i.prst};
            if (ret.first > res.first || (ret.first == res.first && ret.second < res.second))
            {
                ret = res;
            }
        }
        if (ret.first == INF)
        {
            ret.first = 0;
        }
        mem.emplace(s, ret);
    }
    return mem[s];
}

void run()
{
    int b, n;
    scanf("%d%d", &b, &n);
    for (int i = 0; i < n; i++)
    {
        int c, p;
        scanf("%s%s%s%d%d", buf, buf + M / 3, buf + M / 3 * 2, &c, &p);
        inp.emplace_back(buf);
        grf[inp.back()].push_back({buf + M / 3, c, p});
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << inp[i] << endl;
    //     for (auto &&j : grf[inp[i]])
    //     {
    //         cout << j.name << " " << j.cost << " " << j.prst << "\n";
    //     }
    // }
    for (int i = 0; i < n; i++)
    {
        if (mem.find(inp[i]) == mem.end())
        {
            dfs(inp[i]);
        }
    }
    // for (auto &&i : mem)
    // {
    //     cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
    // }
    dp.resize(b + 1, 0);
    ans.resize(b + 1, 0);
    for (auto &&i : mem)
    {
        swap(ans, dp);
        for (int j = 0; j <= b; j++)
        {
            ans[j] = max(dp[j], j >= i.second.first ? dp[j - i.second.first] + i.second.second : 0);
        }
        // for (int j = 0; j <= b; j++)
        // {
        //     cout << ans[j] << "\t";
        // }
        // cout << endl;
        assert(is_sorted(ans.begin(), ans.end()));
    }
    printf("%d\n%d\n", ans[b], (int)(lower_bound(ans.begin(), ans.end(), ans[b]) - ans.begin()));
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