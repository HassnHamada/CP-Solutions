#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 26, L = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    int mn = arr[1], mx = arr[1];
    ll ans = 0;
    for (int i = 2; i <= n; i++)
    {
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
        ans += abs(arr[i - 1] - arr[i]);
    }
    if (arr[1] == mn || arr[n] == mn)
    {
        ans += mn - 1;
    }
    else
    {
        ans += min({2 * (mn - 1), arr[1] - 1, arr[n] - 1});
    }
    if (mx < x)
    {
        if (arr[1] == mx || arr[n] == mx)
        {
            ans += x - mx;
        }
        else
        {
            ans += min({2 * (x - mx), x - arr[1], x - arr[n]});
        }
    }
    printf("%lld\n", ans);
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
