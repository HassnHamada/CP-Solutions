#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2e3 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

struct DT
{
    int x1, x2, y;

    DT() {}
    DT(int _x1, int _x2, int _y)
    {
        x1 = _x1;
        x2 = _x2;
        y = _y;
    }
    bool operator<(const DT &other) const
    {
        if (y == other.y)
        {
            return x1 < other.x1;
        }
        return y < other.y;
    }
} inp[N];

bool com_y(const DT self, const DT other)
{
    return self.y < other.y;
}

bool com_x1(const DT self, const DT other)
{
    return self.x1 < other.x1;
}
bool com_x2(const DT self, const DT other)
{
    return self.x2 < other.x2;
}

set<tuple<int, int, int>> vis;

int n, q;
int ans[N];

void solve(int l, int r, int d)
{
    // cout << l << " " << r << " " << d << endl;
    if (vis.find({l, r, d}) != vis.end())
    {
        return;
    }
    vis.insert({l, r, d});
    if (d == n)
    {
        memset(ans + l, -1, sizeof(ans[0]) * (r - l + 1));
        return;
    }
    int lby = lower_bound(inp, inp + q, DT(0, 0, d), com_y) - inp,
        rby = upper_bound(inp, inp + q, DT(0, 0, d), com_y) - inp;
    if (lby == q || inp[lby].y > d)
    {
        solve(l, r, inp[lby].y);
        return;
    }
    // assert(is_sorted(inp + lby, inp + rby, com_x1));
    // assert(is_sorted(inp + lby, inp + rby, com_x2));
    int lbx = lower_bound(inp + lby, inp + rby, DT(0, l, 0), com_x2) - inp,
        rbx = upper_bound(inp + lby, inp + rby, DT(r, 0, 0), com_x1) - inp;
    if (lbx == rby || inp[lbx].y > d)
    {
        solve(l, r, inp[lbx].y);
        return;
    }
    if (inp[lbx].x1 > l)
    {
        solve(l, min(inp[lbx].x1, r), d + 1);
    }
    else
    {
        solve(inp[lbx].x1, inp[lbx].x1, d + 1);
    }
    for (int i = lbx; i < rbx; i++)
    {
        // assert(inp[i].y == d);
        if (inp[i].x2 >= r)
        {
            solve(inp[i].x2, inp[i].x2, d + 1);
            break;
        }
        if (inp[i + 1].y > d)
        {
            solve(inp[i].x2, r, d + 1);
            break;
        }
        solve(inp[i].x2, min(inp[i + 1].x1, r), d + 1);
    }
}

void run()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d%d", &inp[i].x1, &inp[i].x2, &inp[i].y);
    }
    sort(inp, inp + q);
    solve(1, n, 1);
    printf("%d\n", (int)count(ans + 1, ans + n + 1, -1));
    memset(ans + 1, 0, sizeof(ans[0]) * n);
    vis.clear();
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}