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
}

void push_down1(int i, int s, int e)
{
    int m = (e - s) / 2 + s, l = 2 * i + 1, r = l + 1;
}

void add1(int qs, int qe, int qv, int i = 0, int s = 0, int e = n - 1)
{
    if (qe < s || qs > e)
    {
        return;
    }
    if (qs >= s && qe <= e)
    {
        seg[i] = seg[i] + qv * (qe - qs + 1);
        laz1[i] = qv;
        return;
    }
    if (laz1[i])
    {
        push_down1(i, s, e);
    }
    int m = (e - s) / 2 + s, l = 2 * i + 1, r = l + 1;
    add1(qs, qe, qv, l, s, m);
    add1(qs, qe, qv, r, m + 1, e);
}
}

void run()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
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
        }
        else if (t == 2)
        {
            int a, b, x;
            scanf("%d%d%d", &a, &b, &x);
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
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}