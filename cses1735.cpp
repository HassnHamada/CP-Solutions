#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 18, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll arr[N], seg[N << 1], laz1[N << 1], laz2[N << 1];
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

void push_down1(int i, int s, int e)
{
    int m = (e - s) / 2 + s, l = 2 * i + 1, r = l + 1;
    assert(laz1[i]);
    assert(laz2[i] == 0);
    if (e > s)
    {
        seg[l] += laz1[i] * (m - s + 1);
        seg[r] += laz1[i] * (e - m);
        if (laz2[l])
        {
            assert(laz1[l] == 0);
            laz2[l] += laz1[i];
            assert(seg[l] == laz2[l] * (m - s + 1));
        }
        else
        {
            laz1[l] += laz1[i];
        }
        if (laz2[r])
        {
            assert(laz1[r] == 0);
            laz2[r] += laz1[i];
            assert(seg[r] == laz2[r] * (e - m));
        }
        else
        {
            laz1[r] += laz1[i];
        }
    }
    laz1[i] = 0;
}

void push_down2(int i, int s, int e)
{
    int m = (e - s) / 2 + s, l = 2 * i + 1, r = l + 1;
    assert(laz1[i] == 0);
    assert(laz2[i]);
    if (e > s)
    {
        seg[l] = laz2[i] * (m - s + 1);
        seg[r] = laz2[i] * (e - m);
        if (laz1[l])
        {
            assert(laz2[l] == 0);
            laz1[l] = 0;
        }
        if (laz1[r])
        {
            assert(laz2[r] == 0);
            laz1[r] = 0;
        }
        laz2[l] = laz2[i];
        laz2[r] = laz2[i];
    }
    laz2[i] = 0;
}

void add1(int qs, int qe, int qv, int i = 0, int s = 0, int e = n - 1)
{
    if (qe < s || qs > e)
    {
        return;
    }
    int t = 0;
    if (laz1[i])
    {
        t |= 1;
        push_down1(i, s, e);
    }
    if (laz2[i])
    {
        t |= 2;
        push_down2(i, s, e);
    }
    assert(t != 3);
    if (s >= qs && e <= qe)
    {
        assert(laz1[i] == 0);
        assert(laz2[i] == 0);
        laz1[i] = qv;
        seg[i] += laz1[i] * (e - s + 1);
        return;
    }
    int m = (e - s) / 2 + s, l = 2 * i + 1, r = l + 1;
    add1(qs, qe, qv, l, s, m);
    add1(qs, qe, qv, r, m + 1, e);
    seg[i] = seg[l] + seg[r];
}

void add2(int qs, int qe, int qv, int i = 0, int s = 0, int e = n - 1)
{
    if (qe < s || qs > e)
    {
        return;
    }
    int t = 0;
    if (laz1[i])
    {
        t |= 1;
        push_down1(i, s, e);
    }
    if (laz2[i])
    {
        t |= 2;
        push_down2(i, s, e);
    }
    assert(t != 3);
    if (s >= qs && e <= qe)
    {
        assert(laz1[i] == 0);
        assert(laz2[i] == 0);
        laz2[i] = qv;
        seg[i] = laz2[i] * (e - s + 1);
        return;
    }
    int m = (e - s) / 2 + s, l = 2 * i + 1, r = l + 1;
    add2(qs, qe, qv, l, s, m);
    add2(qs, qe, qv, r, m + 1, e);
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
    int t = 0;
    if (laz1[i])
    {
        t |= 1;
        push_down1(i, s, e);
    }
    if (laz2[i])
    {
        t |= 2;
        push_down2(i, s, e);
    }
    assert(t != 3);
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
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int a, b, x;
            scanf("%d%d%d", &a, &b, &x);
            add1(a - 1, b - 1, x);
        }
        else if (t == 2)
        {
            int a, b, x;
            scanf("%d%d%d", &a, &b, &x);
            add2(a - 1, b - 1, x);
        }
        else if (t == 3)
        {
            int a, b;
            scanf("%d%d", &a, &b);
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