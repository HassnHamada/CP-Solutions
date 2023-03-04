#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, M = 3, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], cnt[N << 1], in[N << 1];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(in, -1, (sizeof(in[0])) * (n + m + 1));
    memset(cnt, 0, (sizeof(cnt[0])) * (n + m + 1));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        in[arr[i]] = 0;
    }
    for (int i = 1, a, b; i <= m; i++)
    {
        scanf("%d%d", &a, &b);
        assert(~in[arr[a - 1]]);
        cnt[arr[a - 1]] += i - in[arr[a - 1]];
        in[arr[a - 1]] = -1;
        in[arr[a - 1] = b] = i;
    }
    for (int i = 1; i <= n + m; i++)
    {
        if (~in[i])
        {
            cnt[i] += m + 1 - in[i];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n + m; i++)
    {
        ans += m * (m + 1ll) / 2 - (m - cnt[i]) * (m - cnt[i] + 1ll) / 2;
    }
    printf("%lld\n", ans);
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}