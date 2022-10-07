#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 3, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

vector<int> tre[N];

pair<int, int> calc(int n, int p, int m)
{
    pair<int, int> ret = {1, 0};
    for (auto &&i : tre[n])
    {
        auto res = calc(i, n, m);
        ret.second += res.second;
        ret.first = max(ret.first, res.first + 1);
    }
    assert(ret.first <= m || n == 1);
    if (n != 1 && p != 1 && ret.first == m)
    {
        return {0, ret.second + 1};
    }
    return ret;
}

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        tre[i].clear();
    }
    for (int i = 2, p; i <= n; i++)
    {
        scanf("%d", &p);
        tre[p].push_back(i);
    }
    int l = 1, h = n;
    while (l < h)
    {
        int m = (h - l) / 2 + l;
        if (calc(1, 0, m).second <= k)
        {
            h = m;
        }
        else
        {
            l = m + 1;
        }
    }
    printf("%d\n", l);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_ok.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}
    