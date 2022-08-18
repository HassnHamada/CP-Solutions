#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e4 + 10, M = 2e5 + 10, L = 1e6 + 10, Q = 174, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

w
int ans[M], frq[L];
int curAns = 0;

void add(int val)
{
    if (frq[val] == 0)
    {
        curAns += 1;
    }
    frq[val] += 1;
}
void del(int val)
{
    assert(frq[val]);
    frq[val] -= 1;
    if (frq[val] == 0)
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
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        qqq[i].i = i;
        scanf("%d%d", &qqq[i].l, &qqq[i].r);
    }
    sort(qqq, qqq + q);
    for (int i = 0; i < q; i++)
    {
        updateSE(qqq[i].l - 1, qqq[i].r - 1);
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
