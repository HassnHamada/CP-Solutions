#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    ll ans = 1, c = count(arr, arr + n, 1);
    for (int i = 0; c > 1;)
    {
        if (arr[i++])
        {
            int j = i - 1;
            for (c--; i < n && arr[i] == 0; i++);
            ans *= (i - j);
        }
    }
    printf("%lld\n", c ? ans : 0ll);
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}