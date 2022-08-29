#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 5, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

pair<int, int> pnt[N];

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
            if (max(a.len(), b.len()) < l.len())
            {
                return true;
            }
        }
        if (v2 == 0)
        {
            Line a{x2, y2, l.x1, l.y1}, b{x2, y2, l.x2, l.y2};
            if (max(a.len(), b.len()) < l.len())
            {
                return true;
            }
        }
        if (v3 == 0)
        {
            Line a{l.x1, l.y1, x1, y1}, b{l.x1, l.y1, x2, y2};
            if (max(a.len(), b.len()) < len())
            {
                return true;
            }
        }
        if (v4 == 0)
        {
            Line a{l.x2, l.y2, x1, y1}, b{l.x2, l.y2, x2, y2};
            if (max(a.len(), b.len()) < len())
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
    ll len() const
    {
        return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    }
    bool operator<(const Line &l) const
    {
        return len() < l.len();
    }
    bool operator>(const Line &l) const
    {
        return len() > l.len();
    }
};

struct DSU
{
    int per[N];
    void init(int n)
    {
        iota(per, per + n, 0);
    }
    void join(int a, int b)
    {
        per[b = find(b)] = a = find(a);
    }
    int find(int a)
    {
        return a == per[a] ? a : per[a] = find(per[a]);
    }
    bool isCon(int a, int b)
    {
        return find(a) == find(b);
    }
} tre;

vector<Line> lin;
vector<int> ans;
vector<int> grf[N];
int n;
bool vis[N];

void dfs(int cn = 1)
{
    cout << cn << " " << grf[cn].size() << endl;
    vis[cn] = true;
    ans.push_back(cn);
    assert(cn == 1 || (int)grf[cn].size() == 2);
    for (auto &&i : grf[cn])
    {
        if (vis[i])
        {
            continue;
        }
        dfs(i);
        break;
    }
}

bool solve(Line &p, int cn)
{
    assert((int)ans.size() == (int)lin.size() + 1);

    if ((int)ans.size() == n)
    {
        Line l{pnt[cn].first, pnt[cn].second, pnt[1].first, pnt[1].second};
        bool ok = true;
        for (auto &&j : lin)
        {
            if (l.inter(j))
            {
                ok = false;
            }
        }
        return ok;
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            if (vis[i])
            {
                continue;
            }
            Line l{pnt[cn].first, pnt[cn].second, pnt[i].first, pnt[i].second};
            bool ok = true;
            for (auto &&j : lin)
            {
                if (l.inter(j))
                {
                    ok = false;
                }
            }
            if (!ok)
            {
                continue;
            }
        }
    }
    // return false;
}

void run()
{
    // Input
    //      Line 1 : n the number of points 3 <= n <= 1e3
    //      Next n line : each line has two values -1e3 <= x, y <= 1e3 -Points are distinct-
    // Task
    //      Conect the points with lines to create a polygon -lines must not intersect nor coincide-
    //      All points must be conected
    //      Each pint must be conected to other two points
    //      Must start from point one
    // Output
    //      Print any permutation of length n + 1 where each two consecutive numbers represent that there is a line connecting these two points
    //      The output must start and end with one
    //      if n equals five a possible answer may be [1, 2, 3, 4, 5, 1] or [1, 5, 2, 3, 4, 1] but not [2, 3, 4, 5, 1, 2] nor [1, 2, 3, 2, 1]
    //      If there is no answer print -1
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &pnt[i].first, &pnt[i].second);
    }
    bool ok = false;
    ans.push_back(1);
    for (int i = 2; !ok && i <= n; i++)
    {
        Line l{pnt[1].first, pnt[1].second, pnt[i].first, pnt[i].second};
        vis[i] = true;
        lin.push_back(l);
        ans.push_back(i);
        if (solve(l, i))
        {
            ok = true;
        }
        vis[i] = false;
        lin.pop_back();
    }
    ans.push_back(1);
    if (ok)
    {
        assert((int)(ans.size()) == n + 1);
        for (int i = 0; i <= n; i++)
        {
            printf("%d%c", ans[i], " \n"[i == n]);
        }
    }
    else
    {
        printf("-1\n");
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