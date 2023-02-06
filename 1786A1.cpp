#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

map<int, pair<int, int>> ans;

void run()
{
    int n;
    scanf("%d", &n);
    const int fn = n;
    if (ans.find(n) == ans.end())
    {
        pair<int, int> p = {0, 0};
        for (int i = 0; n; i++)
        {
            assert(n > 0);
            if (i & 1)
            {
                p.second += min(n, i * 4 + 1);
            }
            else
            {
                p.first += min(n, i * 4 + 1);
            }
            n -= min(n, i * 4 + 1);
            // printf("%d %d\n", p.first, p.second);
        }
        ans.emplace(fn, p);
    }
    printf("%d %d\n", ans[fn].first, ans[fn].second);
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}