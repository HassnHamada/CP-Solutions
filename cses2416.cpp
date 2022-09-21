#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 18, M = 448, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], nxt[N], prv[N];
ll ans[N], curAns;

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

int s, e;

void addL(int val)
{
    curAns += max(0, mx - val);
    mx = max(mx, val);
}

void addR(int ind)
{
    curAns += (grt[ind] - ind - 1) * arr[ind] - acc[grt[ind] - 1] - acc[ind];
}

void delL(int val)
{
    // if (--frq[val] == 0)
    // {
    //     curAns -= 1;
    // }
}

void delR(int val)
{
    // if (--frq[val] == 0)
    // {
    //     curAns -= 1;
    // }
}
void updateSE(int qs, int qe)
{
    while (e < qe + 1)
    {
        addL(arr[e++]);
    }
    while (s > qs)
    {
        addR(--s);
    }
    while (s < qs)
    {
        delR(arr[s++]);
    }
    while (e > qe + 1)
    {
        delL(arr[--e]);
    }
}

void run()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
        acc[i] = arr[i] + acc[i - 1];
    }
    acc[n + 1] = acc[n];
    stack<int> stk;
    for (int i = 1; i <= n; i++)
    {
        while (!stk.empty() && arr[stk.top()] < arr[i])
        {
            grt[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    while (!stk.empty())
    {
        grt[stk.top()] = n + 1;
        stk.pop();
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