#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
char str[N];

void run()
{
    int n, c, q;
    scanf("%d%d%d", &n, &c, &q);
    scanf("%s", str);
    vector<pair<ll, ll>> seg;
    seg.emplace_back(0, n);
    for (int i = 0; i < c; i++)
    {
        ll l, r;
        scanf("%lld%lld", &l, &r);
        seg.emplace_back(l - 1, seg.back().second + r - l + 1);
    }
    for (int i = 0; i < q; i++)
    {
        ll t;
        scanf("%lld", &t);
        t -= 1;
        for (int j = c; j; j--)
        {
            if (t >= seg[j - 1].second && t < seg[j].second)
            {
                t = seg[j].first + t - seg[j - 1].second;
            }
        }
        assert(t < n);
        printf("%c\n", str[t]);
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