#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int N = 2e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
struct Point
{
    ll x, y;
    int id;
} pnt[N], buf[N];
struct comX
{
    bool operator()(const Point &p1, const Point &p2) const
    {
        if (p1.x == p2.x)
        {
            return p1.y < p2.y;
        }
        return p1.x < p2.x;
    }
};
struct comY
{
    bool operator()(const Point &p1, const Point &p2) const
    {
        return p1.y < p2.y;
    }
};

ll ans = INT64_MAX;

void updateAns(const Point &p1, const Point &p2)
{
    ll xd = abs(p1.x - p2.x), yd = abs(p1.y - p2.y);
    ans = min(ans, xd * xd + yd * yd);
}

void solve(int l, int r)
{
    if (r - l <= 3)
    {
        for (int i = l; i < r; i++)
        {
            for (int j = i + 1; j < r; j++)
            {
                updateAns(pnt[i], pnt[j]);
            }
        }
        sort(pnt + l, pnt + r, comY());
        return;
    }
    int m = (r - l) / 2 + l;
    solve(l, m);
    solve(m, r);
    merge(pnt + l, pnt + m, pnt + m, pnt + r, buf, comY());
    copy(buf, buf + r - l, pnt + l);
    for (int i = l, sz = 0; i < r; i++)
    {
        ll xd = abs(pnt[i].x - pnt[m].x);
        if (xd < ans)
        {
            for (int j = sz - 1; j >= 0; j--)
            {
                ll yd = abs(buf[j].y - pnt[i].y);
                if (yd >= ans)
                {
                    break;
                }
                updateAns(pnt[i], buf[j]);
            }
            buf[sz++] = pnt[i];
        }
    }
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld%lld", &pnt[i].x, &pnt[i].y);
        pnt[i].id = i;
    }
    sort(pnt, pnt + n, comX());
    solve(0, n);
    printf("%lld\n", ans);
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