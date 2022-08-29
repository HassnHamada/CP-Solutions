#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, Q = 317, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], ans[N];

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

int frq[N], ffrq[N], curAns;

void add(int val)
{
    if (ffrq[++frq[val]]++ == 0)
    {
        curAns += 1;
    }
}
void del(int val)
{
    if (--ffrq[frq[val]--] == 0)
    {
        curAns -= 1;
    }
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
        scanf("%d%d", &qqq[i].l, &qqq[i].r);
        qqq[i].i = i;
    }
    sort(qqq, qqq + q);
    for (int i = 0; i < q; i++)
    {
        updateSE(qqq[i].l, qqq[i].r);
        ans[qqq[i].i] = curAns;
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
