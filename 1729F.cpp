#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

const int N = 2e5 + 10, M = 65, L = 4, MOD = 9, HV = 151, INF = 0x3f3f3f3f;

char inp[N];
int val[N];

void solve(map<int, vector<int>> &mmm)
{
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    int v = (val[r] - val[l - 1] + MOD) % MOD;
    vector<pair<int, int>> ans;
    for (auto &&i : mmm)
    {
        for (auto &&j : mmm)
        {
            if (i.first == j.first && i.second.size() == 1)
            {
                continue;
            }
            int w = (i.first * v + j.first) % MOD;
            if (w == k)
            {
                ans.push_back({i.second[0], j.second[i.first == j.first]});
            }
        }
    }
    if (ans.empty())
    {
        printf("-1 -1\n");
    }
    else
    {
        sort(ans.begin(), ans.end());
        printf("%d %d\n", ans[0].first, ans[0].second);
    }
}

void run()
{
    scanf("%s", inp);
    int w, m, n = strlen(inp);
    scanf("%d%d", &w, &m);
    for (int i = 0; i < n; i++)
    {
        val[i + 1] = (val[i] + inp[i] - '0' + MOD) % MOD;
    }
    map<int, vector<int>> mmm;
    for (int i = w; i <= n; i++)
    {
        mmm[(val[i] - val[i - w] + MOD) % MOD].push_back(i - w + 1);
    }
    while (m--)
    {
        solve(mmm);
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