#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int inp[N];

ll solve(int u, int sz, multiset<int, greater<int>> &sss)
{
    // cout << u << " " << sz << " " << sss.size() << endl;
    assert(u <= sz);
    if (sss.empty())
    {
        return 1;
    }
    auto it = sss.lower_bound(sz - u);
    if (it == sss.end())
    {
        return 1 + solve(0, sz, sss);
    }
    int v = *it;
    sss.erase(it);
    return v + solve(v, sz, sss);
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", inp + i);
    }
    // sort(inp, inp + n);
    multiset<int, greater<int>> sss(inp, inp + n);
    // for (auto &&i : sss)
    // {
    //     cout << i << " ";
    // }
    printf("%lld\n", solve(0, m, sss));
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