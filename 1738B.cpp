#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 2, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", arr + i);
    }
    bool ok = true;
    int v = INT32_MAX;
    for (int i = k - 1; ok && i; i--)
    {
        if (arr[i] - arr[i - 1] > v)
        {
            ok = false;
        }
        else
        {
            v = arr[i] - arr[i - 1];
        }
    }
    if (ok)
    {
        if (arr[0] >= 0)
        {
            ok = (arr[0] + n - k) / (n - k + 1) <= v;
        }
        if (arr[0] < 0)
        {
            ok = arr[0] / (n - k + 1) <= v;
        }
    }
    printf(ok ? "YES\n" : "NO\n");
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
