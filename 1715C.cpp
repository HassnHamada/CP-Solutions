#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 6, MOD = 1e9 + 9, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    ll ans = 0;
    for (ll i = 1, j = 0; i <= n; i++)
    {
        j += arr[i] == arr[i - 1] ? 1 : i;
        ans += j;
    }
    while (m--)
    {
        ll i, x;
        scanf("%lld%lld", &i, &x);
        if (arr[i] == arr[i + 1] && arr[i + 1] != x)
        {
            ans += i * (n - i);
        }
        else if (arr[i] != arr[i + 1] && arr[i + 1] == x)
        {
            ans -= i * (n - i);
        }
        if (arr[i] == arr[i - 1] && arr[i - 1] != x)
        {
            ans += (i - 1) * (n - i + 1);
        }
        else if (arr[i] != arr[i - 1] && arr[i - 1] == x)
        {
            ans -= (i - 1) * (n - i + 1);
        }
        arr[i] = x;
        printf("%lld\n", ans);
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