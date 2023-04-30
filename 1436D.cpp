#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 1e6 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int par[N], ppl[N];
vector<int> nxt[N];

tuple<ll, ll, ll> solve(int n = 1)
{
    if (nxt[n].empty())
    {
        return {ppl[n], ppl[n], 1};
    }
    ll ra = 0, rb = 0, rc = 0;
    for (auto &&i : nxt[n])
    {
        auto [a, b, c] = solve(i);
        ra += a;
        rb = max(rb, b);
        rc += c;
    }
    assert(rc);
    assert(rc * rb >= ra);
    if (rc * rb < ppl[n] + ra)
    {
        rb += (ppl[n] - rc * rb + ra + rc - 1) / rc;
        assert(rc * (rb - 1) < ppl[n] + ra);
    }
    assert(rc * rb >= ppl[n] + ra);
    return {ra + ppl[n], rb, rc};
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", par + i);
        nxt[par[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", ppl + i);
    }
    printf("%lld\n", get<1>(solve()));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}