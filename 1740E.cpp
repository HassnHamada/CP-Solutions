#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 100, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int ans[N], dep[N];
vector<int> tre[N];

void dfs(int n)
{
    dep[n] = 1;
    int sm = 0;
    for (auto &&i : tre[n])
    {
        dfs(i);
        sm += ans[i];
        dep[n] = max(dep[n], dep[i] + 1);
    }
    ans[n] = max(sm, dep[n]);
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 2, p; i <= n; i++)
    {
        scanf("%d", &p);
        tre[p].push_back(i);
    }
    dfs(1);
    printf("%d\n", ans[1]);
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