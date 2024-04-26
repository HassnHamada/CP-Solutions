#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 20, M = 1e5 + 10, Q = 1000, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char str[N];
int n;
struct T
{
    int l, r, v;
} tre[N << 1];

void build(int i = 0, int s = 0, int e = n - 1)
{
    if (s == e)
    {
        tre[i] = {str[s] == '(', str[s] == ')', 0};
        return;
    }
    int l = 2 * i + 1, r = l + 1, m = (e - s) / 2 + s;
    build(l, s, m);
    build(r, m + 1, e);
    int mn = min(tre[l].l, tre[r].r);
    tre[i] = {tre[l].l + tre[r].l - mn,
              tre[l].r + tre[r].r - mn,
              tre[l].v + tre[r].v + mn};
}

T get(int qs, int qe, int i = 0, int s = 0, int e = n - 1)
{
    if (s > qe || e < qs)
    {
        return {0, 0, 0};
    }
    if (s >= qs && e <= qe)
    {
        return tre[i];
    }
    int l = 2 * i + 1, r = l + 1, m = (e - s) / 2 + s;
    T lq = get(qs, qe, l, s, m), rq = get(qs, qe, r, m + 1, e);
    int mn = min(lq.l, rq.r);
    return {lq.l + rq.l - mn,
            lq.r + rq.r - mn,
            lq.v + rq.v + mn};
}

void run()
{
    scanf("%s", str);
    n = strlen(str);
    build();
    int m;
    scanf("%d", &m);
    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", get(l - 1, r - 1).v * 2);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}