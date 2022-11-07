#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 100, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

ll arr[N];
map<ll, int> frq;

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", arr + i);
        frq[arr[i]]++;
    }
    sort(arr, arr + n);
    int m = unique(arr, arr + n) - arr;
    if (m == 1)
    {
        printf("0\n");
    }
    else if (m == 2)
    {
        printf("%lld\n", 2 * (arr[1] - arr[0]));
    }
    else
    {
        ll ans = arr[m - 1] - arr[0] + max(arr[1] - arr[0], arr[m - 1] - arr[m - 2]);
        for (int i = 0; i < m; i++)
        {
            if (i && i + 1 < m)
            {
                ans = max(ans, 2 * arr[i + 1] - arr[i] - arr[0]);
            }
            if (i + 1 < m && frq[arr[i]] >= 2)
            {
                ans = max(ans, 2 * (arr[i + 1] - arr[i]));
            }
            if (i != m - 1 && i - 2 >= 0)
            {
                ans = max(ans, arr[m - 1] + arr[i] - 2 * arr[i - 1]);
            }
            if (i - 1 >= 0 && frq[arr[i]] >= 2)
            {
                ans = max(ans, 2 * (arr[i] - arr[i - 1]));
            }
        }
        printf("%lld\n", ans);
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