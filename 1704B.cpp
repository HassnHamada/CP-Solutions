#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n, x;
    scanf("%d%d", &n, &x);
    int ans = 0;
    for (int i = 0, v, mn = INF, mx = -INF; i < n; i++)
    {
        // scanf("%d", arr + i);
        scanf("%d", &v);
        mn = min(mn, v);
        mx = max(mx, v);
        if (mx - mn > x * 2)
        {
            mn = mx = v;
            ans += 1;
        }
    }
    printf("%d\n", ans);
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
