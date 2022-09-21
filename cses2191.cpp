#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int N = 1e3 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

struct Line
{
    ll x1, y1, x2, y2;
    bool inter(Line &l)
    {
        ll v1 = X(l.x1 - x1, l.y1 - y1, l.x2 - x1, l.y2 - y1),
           v2 = X(l.x1 - x2, l.y1 - y2, l.x2 - x2, l.y2 - y2),
           v3 = X(x1 - l.x1, y1 - l.y1, x2 - l.x1, y2 - l.y1),
           v4 = X(x1 - l.x2, y1 - l.y2, x2 - l.x2, y2 - l.y2);
        if (v1 && v2 && v3 && v4)
        {
            return ((v1 > 0 && v2 < 0) || (v1 < 0 && v2 > 0)) &&
                   ((v3 > 0 && v4 < 0) || (v3 < 0 && v4 > 0));
        }
        if (v1 == 0)
        {
            Line a{x1, y1, l.x1, l.y1}, b{x1, y1, l.x2, l.y2};
            if (max(a.len(), b.len()) <= l.len())
            {
                return true;
            }
        }
        if (v2 == 0)
        {
            Line a{x2, y2, l.x1, l.y1}, b{x2, y2, l.x2, l.y2};
            if (max(a.len(), b.len()) <= l.len())
            {
                return true;
            }
        }
        if (v3 == 0)
        {
            Line a{l.x1, l.y1, x1, y1}, b{l.x1, l.y1, x2, y2};
            if (max(a.len(), b.len()) <= len())
            {
                return true;
            }
        }
        if (v4 == 0)
        {
            Line a{l.x2, l.y2, x1, y1}, b{l.x2, l.y2, x2, y2};
            if (max(a.len(), b.len()) <= len())
            {
                return true;
            }
        }
        return false;
    }
    ll X(ll a, ll b, ll c, ll d)
    {
        return a * d - b * c;
    }
    ll len()
    {
        return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    }
};

pair<int, int> pnt[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &pnt[i].first, &pnt[i].second);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        Line l;
        ans += l.X(pnt[i].first, pnt[i].second, pnt[(i + 1) % n].first, pnt[(i + 1) % n].second);
    }
    printf("%lld\n", abs(ans));
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