#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e3 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int arr[N], bbb[N];

void run()
{
    int n;
    scanf("%d\r\n", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bbb[i] += arr[i] > arr[j];
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            bbb[j] -= arr[j] > arr[i];
        }
        int t = 0;
        for (int j = 0; j < i; j++)
        {
            t += bbb[j];
        }
        for (int j = 0; j < i; j++)
        {
            t -= bbb[j];
            if (arr[i] > arr[j])
            {
                ans += t;
            }
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