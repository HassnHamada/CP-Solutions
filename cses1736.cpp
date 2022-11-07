#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 18, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll arr[N], seg[N << 1];
pair<ll, ll> laz[N << 1];
int n, q;

void build(int i = 0, int s = 0, int e = n - 1)
{
    if (s == e)
    {
        seg[i] = arr[s];
        return;
    }
    int m = (e - s) / 2 + s, l = 2 * i + 1, r = l + 1;
    build(l, s, m);
    build(r, m + 1, e);
    seg[i] = seg[l] + seg[r];
}

void push_down(int i, int s, int e)
{
    int m = (e - s) / 2 + s, l = 2 * i + 1, r = l + 1;
    auto [a, b] = laz[i];
    assert(a && b);
    if (e > s)
    {
        seg[l] += a * (m - s + 1) + (m - s + 1ll) * (m - s) / 2 * b;
        seg[r] += (a + b * (m - s + 1ll)) * (e - m) + (e - m) * (e - m - 1ll) / 2 * b;
        laz[l].first += a;
        laz[l].second += b;
        laz[r].first += a + b * (m - s + 1);
        laz[r].second += b;
    }
    laz[i] = {0, 0};
}

void add(int qs, int qe, int i = 0, int s = 0, int e = n - 1)
{
    if (qe < s || qs > e)
    {
        return;
    }
    if (laz[i].first)
    {
        push_down(i, s, e);
    }
    if (s >= qs && e <= qe)
    {
        assert(laz[i].first == 0);
        assert(laz[i].second == 0);
        seg[i] += (s - qs + 1) * (e - s + 1ll) + (e - s + 1ll) * (e - s) / 2;
        laz[i] = {s - qs + 1, 1};
        return;
    }
    int m = (e - s) / 2 + s, l = 2 * i + 1, r = l + 1;
    add(qs, qe, l, s, m);
    add(qs, qe, r, m + 1, e);
    seg[i] = seg[l] + seg[r];
}

ll get(int qs, int qe, int i = 0, int s = 0, int e = n - 1)
{
    if (qe < s || qs > e)
    {
        return 0;
    }
    if (s >= qs && e <= qe)
    {
        return seg[i];
    }
    if (laz[i].first)
    {
        push_down(i, s, e);
    }
    int m = (e - s) / 2 + s, l = 2 * i + 1, r = l + 1;
    return get(qs, qe, l, s, m) + get(qs, qe, r, m + 1, e);
}
void run()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", arr + i);
    }
    build();
    while (q--)
    {
        int t, a, b;
        scanf("%d%d%d", &t, &a, &b);
        if (t == 1)
        {
            add(a - 1, b - 1);
        }
        else if (t == 2)
        {
            printf("%lld\n", get(a - 1, b - 1));
        }
        else
        {
            assert(false);
        }
    }
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