#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int N = 2e3 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

map<pair<int, int>, map<ll, ll>> lin;
pair<int, int> pnt[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &pnt[i].first, &pnt[i].second);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll a = pnt[i].first - pnt[j].first,
               b = pnt[i].second - pnt[j].second;
            if (a == 0)
            {
                lin[{-1, -1}][a * a + b * b] += 1;
            }
            else if (b == 0)
            {
                lin[{0, 0}][a * a + b * b] += 1;
            }
            else
            {
                ll g = __gcd(a, b);
                lin[{b / g, a / g}][a * a + b * b] += 1;
            }
        }
    }
    ll ans = 0;
    for (auto &&i : lin)
    {
        for (auto &&j : i.second)
        {
            ans += j.second * (j.second - 1) / 2;
        }
    }
    assert(ans % 2 == 0);
    printf("%lld\n", ans / 2);
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