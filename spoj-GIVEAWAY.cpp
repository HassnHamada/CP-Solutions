#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 6e5 + 10, M = 800, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int bit[M][N];

struct Query
{
    int t, a, b, c;
} qqq[N];

int arr[N], srt[N];

void add(int i, int j, int v)
{
    for (i++; i <= M; i += (i & (-i)))
    {
        for (int k = j + 1; k <= N; k += (k & (-k)))
        {
            bit[i - 1][k - 1] += v;
        }
    }
}

int get(int i, int j)
{
    int ret = 0;
    for (i++; i; i -= (i & (-i)))
    {
        for (int k = j + 1; k; k -= (k & (-k)))
        {
            ret += bit[i - 1][k - 1];
        }
    }
    return ret;
}

int calc(int i, int v)
{
    int b = i / M;
    int ret = count_if(arr + b * M, arr + i + 1, [&v](int j)
                       { return j >= v; });
    if (b)
    {
        ret += get(b - 1, N - 1) - get(b - 1, v - 1);
    }
    return ret;
}

void run()
{
    int n, q, sz = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
        srt[sz++] = arr[i];
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &qqq[i].t);
        scanf("%d%d", &qqq[i].a, &qqq[i].b);
        if (qqq[i].t == 0)
        {
            scanf("%d", &qqq[i].c);
            srt[sz++] = qqq[i].c;
        }
        else
        {
            srt[sz++] = qqq[i].b;
        }
    }
    sort(srt, srt + sz);
    sz = unique(srt, srt + sz) - srt;
    for (int i = 1; i <= n; i++)
    {
        arr[i] = lower_bound(srt, srt + sz, arr[i]) - srt + 1;
        add(i / M, arr[i], 1);
    }
    for (int i = 0; i < q; i++)
    {
        if (qqq[i].t == 0)
        {
            qqq[i].c = lower_bound(srt, srt + sz, qqq[i].c) - srt + 1;
            printf("%d\n", calc(qqq[i].b, qqq[i].c) - calc(qqq[i].a - 1, qqq[i].c));
        }
        else
        {
            qqq[i].b = lower_bound(srt, srt + sz, qqq[i].b) - srt + 1;
            add(qqq[i].a / M, arr[qqq[i].a], -1);
            arr[qqq[i].a] = qqq[i].b;
            add(qqq[i].a / M, arr[qqq[i].a], 1);
        }
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
