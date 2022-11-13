#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 30, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

ll arr[N], acc[N];

int ans(int q, int n)
{
    int l = 0, h = n;
    while (l < h)
    {
        int m = (h - l + 1) / 2 + l;
        if (arr[m] <= q)
        {
            l = m;
        }
        else
        {
            h = m - 1;
        }
    }
    return l;
}

void run()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", arr + i);
        acc[i] = acc[i - 1] + arr[i];
        arr[i] = max(arr[i], arr[i - 1]);
    }
    for (int i = 0, v; i < q; i++)
    {
        scanf("%d", &v);
        printf("%lld%c", acc[ans(v, n)], " \n"[i + 1 == q]);
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}
