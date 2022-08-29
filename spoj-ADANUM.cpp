#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, Q = 448, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], srt[N];

struct Query
{
    int l, r, i;
    bool operator<(const Query &other) const
    {
        if (this->l / Q == other.l / Q)
        {
            return this->r < other.r;
        }
        return this->l / Q < other.l / Q;
    }
} qqq[N];

int frq[N];
ll ans[N], curAns;

struct BIT
{
    int bit[N], sz = 0;
    void add(int i, int v)
    {
        sz += v;
        for (i++; i <= N; i += (i & (-i)))
        {
            bit[i - 1] += v;
        }
    }
    int get(int i)
    {
        int ret = 0;
        for (i++; i; i -= (i & (-i)))
        {
            ret += bit[i - 1];
        }
        return ret;
    }
} uni;

void add(int val)
{
    if (frq[val])
    {
        ll v = uni.get(frq[val] - 1);
        curAns -= (uni.sz - v) * frq[val] + v;
        uni.add(frq[val], -1);
    }
    uni.add(++frq[val], 1);
    ll v = uni.get(frq[val] - 1);
    curAns += (uni.sz - v) * frq[val] + v;
}
void del(int val)
{
    ll v = uni.get(frq[val] - 1);
    curAns -= (uni.sz - v) * frq[val] + v;
    uni.add(frq[val]--, -1);
    if (frq[val])
    {
        uni.add(frq[val], 1);
        v = uni.get(frq[val] - 1);
        curAns += (uni.sz - v) * frq[val] + v;
    }
}

int s, e;

void updateSE(int qs, int qe)
{
    // cout << "update " << qs << " " << qe << endl;
    while (e < qe + 1)
    {
        add(arr[e++]);
    }
    while (s > qs)
    {
        add(arr[--s]);
    }
    while (s < qs)
    {
        del(arr[s++]);
    }
    while (e > qe + 1)
    {
        del(arr[--e]);
    }
    // cout << "end" << endl;
}

void run()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        srt[i] = arr[i];
    }
    sort(srt, srt + n);
    int m = unique(srt, srt + n) - srt;
    for (int i = 0; i < n; i++)
    {
        arr[i] = lower_bound(srt, srt + m, arr[i]) - srt;
    }
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d", &qqq[i].l, &qqq[i].r);
        qqq[i].i = i;
    }
    sort(qqq, qqq + q);
    for (int i = 0; i < q; i++)
    {
        updateSE(qqq[i].l - 1, qqq[i].r - 1);
        ans[qqq[i].i] = curAns;
    }
    for (int i = 0; i < q; i++)
    {
        printf("%lld\n", ans[i]);
    }
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
