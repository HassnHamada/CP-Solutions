#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

pair<int, int> inp[N];

ll f(const pair<int, int> &point)
{
    return 1ll * point.first * point.second;
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &inp[i].first, &inp[i].second);
    }
    sort(inp, inp + n);
    ll ans = 0;
    for (int i = 0; i < n;)
    {
        pair<int, int> point = inp[i];
        for (i++; i < n; i++)
        {
            pair<int, int> new_point = {max(point.first, inp[i].first),
                                        max(point.second, inp[i].second)};
            if (f(point) + f(inp[i]) < f(new_point))
            {
                break;
            }
            point = new_point;
        }
        ans += f(point);
    }
    printf("%lld\n", ans);
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