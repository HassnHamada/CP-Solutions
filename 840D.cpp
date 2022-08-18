#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 10, M = 550, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], frq[N], ans[N];

struct Query
{
    int l, r, k, i;
    bool operator<(const Query &other) const
    {
        if (this->l / M == other.l / M)
        {
            return this->r < other.r;
        }
        return this->l / M < other.l / M;
    }
} qqq[N];

struct DT
{
    int f, s;
    bool operator<(const DT &other) const
    {
        if (this->f == other.f)
        {
            return this->s < other.s;
        }
        return other.f < this->f;
    }
};

set<DT> sss;

void add(int val)
{
    sss.erase({frq[val], val});
    sss.insert({++frq[val], val});
}
void del(int val)
{
    sss.erase({frq[val], val});
    sss.insert({--frq[val], val});
}

int s, e;

void updateSE(int qs, int qe)
{
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
}

void run()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d%d", &qqq[i].l, &qqq[i].r, &qqq[i].k);
        qqq[i].i = i;
    }
    sort(qqq, qqq + q);
    for (int i = 0; i < q; i++)
    {
        updateSE(qqq[i].l - 1, qqq[i].r - 1);
        auto it = sss.begin();
        ans[qqq[i].i] = it->f > (qqq[i].r - qqq[i].l + 1) / qqq[i].k ? it->s : -1;
    }
    for (int i = 0; i < q; i++)
    {
        printf("%d\n", ans[i]);
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
