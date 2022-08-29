#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    ll ans = 0;
    int i = 0, j = 1;
    while (true)
    {
        while (i < n - 1 && arr[i] == 0)
        {
            i += 1;
        }
        j = max(j, i + 1);
        while (j < n && arr[j] != 0)
        {
            j += 1;
        }
        if (j == n)
        {
            break;
        }
        arr[i] -= 1;
        arr[j] += 1;
        ans += 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        ans += arr[i];
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