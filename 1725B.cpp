#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 2e2 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    sort(arr, arr + n);
    int jj = n - 1, ans = 0;
    while (jj >= 0 && 1ll * n * arr[jj] >= d + 1)
    {
        ans += 1;
        n -= (d + arr[jj]) / arr[jj];
        jj -= 1;
        assert(n >= 0);
    }
    printf("%d\n", ans);
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