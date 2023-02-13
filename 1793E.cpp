#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 10, M = 1e6 + 10, Q = 548, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], dp[N], mx[N], ans[N];

struct Query
{
    int i, v;
    bool operator<(const Query &other) const
    {
        return this->v < other.v;
    }
} qqq[N];

void run()
{
    int n, q;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    sort(arr + 1, arr + n + 1);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = arr[i] > i ? -INF : mx[i - arr[i]] + 1;
        mx[i] = max(mx[i - 1], dp[i]);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &qqq[i].v);
        qqq[i].i = i;
    }
    sort(qqq, qqq + q);
    for (int i = 0, j = 0; i < q; i++)
    {
        while (j < qqq[i].v - 1 && dp[n - j] + j < qqq[i].v)
        {
            j++;
        }
        ans[qqq[i].i] = upper_bound(arr + 1, arr + n + 1 - j, n - j) - arr - 1;
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
