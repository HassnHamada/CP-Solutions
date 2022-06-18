#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 3, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
ll arr[N];

void run()
{
    int n, q;
    scanf("%d%d", &n, &q);
    arr[n] = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", arr + i);
    }
    sort(arr, arr + n);
    for (int i = n - 1; i >= 0; i--)
    {
        arr[i] += arr[i + 1];
    }
    while (q--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%lld\n", arr[n - x] - arr[n - x + y]);
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
