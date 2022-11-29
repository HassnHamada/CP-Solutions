#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 128, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    sort(arr, arr + n);
    ll ans = 0;
    for (int i = 0, j = -1; i < n; i = j)
    {
        j = upper_bound(arr, arr + n, arr[i]) - arr;
        ans += (j - i) / 2;
        i = j;
    }
    for (int i = 0, j = -1; i < n; i = j)
    {
        j = upper_bound(arr, arr + n, arr[i]) - arr;
        ans = max(ans, 1ll * j * (n - j));
        i = j;
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
    {
        run();
    }
    return 0;
}