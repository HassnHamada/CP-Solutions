#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 20, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int sss[N], fff[N];

typedef complex<ll> point;

ll dot(point a, point b)
{
    return (conj(a) * b).real();
}

ll f(point a, ll x)
{
    return dot(a, {x, 1});
}

point line[N << 1];

void add_line(point nw, int v = 0, int l = 0, int r = N)
{
    int m = (l + r) / 2;
    bool lef = f(nw, l) < f(line[v], l);
    bool mid = f(nw, m) < f(line[v], m);
    if (mid)
    {
        swap(line[v], nw);
    }
    if (r - l == 1)
    {
        return;
    }
    else if (lef == mid)
    {
        add_line(nw, 2 * v + 2, m + 1, r);
    }
    else
    {
        add_line(nw, 2 * v + 1, l, m);
    }
}

ll get(int x, int v = 0, int l = 0, int r = N)
{
    int m = (l + r) / 2;
    if (r - l == 1)
    {
        return f(line[v], x);
    }
    else if (x < m)
    {
        return min(f(line[v], x), get(x, 2 * v + 1, l, m));
    }
    else
    {
        return min(f(line[v], x), get(x, 2 * v + 2, m + 1, r));
    }
}

void run()
{
    int n;
    scanf("%d%d", &n, fff);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", sss + i);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", fff + i);
    }
    for (int i = 0; i < (N << 1); i++)
    {
        line[i] = {fff[0], 0};
    }
    for (int i = 1; i < n; i++)
    {
        add_line({fff[i], get(sss[i])});
    }
    printf("%lld\n", get(sss[n]));
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