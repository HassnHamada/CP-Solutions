#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 20, L = 4, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll arr[L][N], mjk[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &arr[i][j]);
        }
    }
    for (ll i = 0, t = -1; i < n; i++)
    {
        t = mjk[i + 1] = max({t + 2, i ? arr[i & 1][i] + 2 : 0, arr[(i & 1) ^ 1][i] + 1});
    }
    for (int i = n - 1; ~i; i--)
    {
        arr[2][i] = arr[0][i] - n + i + 1;
        arr[3][i] = arr[1][i] - n + i + 1;
    }
    for (int i = n - 2; ~i; i--)
    {
        arr[2][i] = max(arr[2][i + 1], arr[2][i]);
        arr[3][i] = max(arr[3][i + 1], arr[3][i]);
    }
    for (int i = 1; i < n; i++)
    {
        arr[0][i] = arr[0][i] - i + 1;
        arr[1][i] = arr[1][i] - i;
        arr[0][i] = max(arr[0][i - 1], arr[0][i]);
        arr[1][i] = max(arr[1][i - 1], arr[1][i]);
    }
    ll ans = INT64_MAX;
    for (int i = 0; i < n; i++)
    {
        ll a = mjk[i];
        ll b = max(arr[i & 1][n - 1] + i - (i && ((i & 1) ^ 1) ? 1 : 0) - a, 0ll) + n - i - (i ? 0 : 1);
        ll c = max(arr[3 - (i & 1)][0] - a - b, 0ll) + n - i;
        ans = min(ans, a + b + c);
    }
    std::printf("%lld\n", ans);
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
