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
    ll X(const Line &other)
    {
        ll vx = x2 - x1, vy = y2 - y1;
        ll ox = other.x2 - other.x1, oy = other.y2 - other.y1;
        return this->X(vx, vy, ox, oy);
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

ll pnt[2][N];
char ans[3][10] = {"OUTSIDE", "INSIDE", "BOUNDARY"};

int pnpoly(int npol, ll *xp, ll *yp, ll x, ll y)
{
    int i, j, c = 0;
    for (i = 0, j = npol - 1; i < npol; j = i++)
    {
        if ((((yp[i] <= y) && (y < yp[j])) || ((yp[j] <= y) && (y < yp[i]))) &&
            (x < 1.0 * (xp[j] - xp[i]) * (y - yp[i]) / (yp[j] - yp[i]) + xp[i]))
            c = !c;
    }
    return c;
}

int solve(ll x, ll y, int n)
{
    for (int i = 0; i < n; i++)
    {
        Line l1 = {pnt[0][i], pnt[1][i], x, y},
             l2 = {pnt[0][i], pnt[1][i], pnt[0][(i + 1) % n], pnt[1][(i + 1) % n]};
        ll w = l1.X(l2);
        Line t1 = {l2.x1, l2.y1, x, y},
             t2 = {l2.x2, l2.y2, x, y};
        if (w == 0 && max(t1.len(), t2.len()) <= l2.len())
        {
            return 2;
        }
    }
    return pnpoly(n, pnt[0], pnt[1], x, y);
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld%lld", &pnt[0][i], &pnt[1][i]);
    }
    for (ll i = 0, x, y; i < m; i++)
    {
        scanf("%lld%lld", &x, &y);
        printf("%s\n", ans[solve(x, y, n)]);
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}