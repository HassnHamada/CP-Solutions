#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 1 << 11, L = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> tre[N];

void dfs(int n, vector<vector<int>> &ans)
{
    for (auto &&i : tre[n])
    {
        if (i != *tre[n].begin())
        {
            ans.emplace_back();
        }
        ans.back().push_back(i);
        dfs(i, ans);
    }
}

void run()
{
    int n, r = -1;
    scanf("%d", &n);
    for (int i = 1, v; i <= n; i++)
    {
        scanf("%d", &v);
        if (i == v)
        {
            r = i;
            continue;
        }
        tre[v].push_back(i);
    }
    assert(r != -1);
    vector<vector<int>> ans;
    ans.emplace_back();
    ans.back().push_back(r);
    dfs(r, ans);
    printf("%d\n", (int)ans.size());
    for (auto &&i : ans)
    {
        printf("%d\n", (int)i.size());
        for (auto &&j : i)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        tre[i].clear();
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
