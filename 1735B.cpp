#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 5e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
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
    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= arr[0] * 2)
        {
            int v = (2 * arr[0] - 1);
            ans += (arr[i] + v - 1) / v - 1;
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
