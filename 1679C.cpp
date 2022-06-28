#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 17, M = 448, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;

int n;

struct BIT
{
    int tre[N], _tre[N];
    void add(int i, int v)
    {
        _tre[i] += v;
        if (_tre[i] <= 0)
        {
            tre[i] = 0;
        }
        else if (_tre[i] > 0)
        {
            tre[i] = 1;
        }
        for (i++; i <= N; i += (i & (-i)))
        {
            tre[i - 1] += v;
        }
    }
    int get(int i)
    {
        int ret = 0;
        for (i++; i; i -= (i & (-i)))
        {
            ret += tre[i - 1];
        }
        return ret;
    }
} bit1, bit2;

struct SEG
{
    int tre[N << 1], _tre[N << 1];
    void add(int q, int v, int i = 0, int s = 0, int e = n)
    {
        if (q > e || q < s)
        {
            return;
        }
        if (s == e)
        {
            assert(s == q);
            _tre[i] += v;
            if (_tre[i] <= 0)
            {
                tre[i] = 0;
            }
            else if (_tre[i] > 0)
            {
                tre[i] = 1;
            }
            return;
        }
        int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
        add(q, v, l, s, m);
        add(q, v, r, m + 1, e);
        tre[i] = tre[l] + tre[r];
        _tre[i] = _tre[l] + _tre[r];
    }
    int get(int qs, int qe, int i = 0, int s = 0, int e = n)
    {
        if (qs > e || qe < s)
        {
            return 0;
        }
        if (s >= qs && e <= qe)
        {
            return tre[i];
        }
        int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
        return get(qs, qe, l, s, m) + get(qs, qe, r, m + 1, e);
    }
} seg1, seg2;

void run()
{
    int q;
    scanf("%d%d", &n, &q);

    while (q--)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            // seg1.add(x, 1);
            // seg2.add(y, 1);
            bit1.add(x, 1);
            bit2.add(y, 1);
        }
        else if (t == 2)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            // seg1.add(x, -1);
            // seg2.add(y, -1);
            bit1.add(x, -1);
            bit2.add(y, -1);
        }
        else if (t == 3)
        {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            cout << bit1.get(x2) << " " << bit1.get(x1 - 1) << endl;
            // bool yes = seg1.get(x1, x2) == x2 - x1 + 1 || seg2.get(y1, y2) == y2 - y1 + 1;
            bool yes = bit1.get(x2) - bit1.get(x1 - 1) == x2 - x1 + 1 || bit2.get(y2) - bit2.get(y1 - 1) == y2 - y1 + 1;
            printf(yes ? "Yes\n" : "No\n");
        }
        else
        {
            assert(false);
        }
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