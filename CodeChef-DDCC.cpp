#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 1e6 + 10, Q = 448, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];
ll ans[N];

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

int frq[M];
ll curAns;

void add(int val)
{
    curAns -= (ll)(frq[val]) * frq[val] * val;
    frq[val] += 1;
    curAns += (ll)(frq[val]) * frq[val] * val;
}
void del(int val)
{
    curAns -= (ll)(frq[val]) * frq[val] * val;
    frq[val] -= 1;
    curAns += (ll)(frq[val]) * frq[val] * val;
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
