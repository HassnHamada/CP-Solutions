#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

bool ok(int i, int n, int t, int h)
{
    if (t == 0)
    {
        return true;
    }
    if (i >= n || n - i < 2 * t - 1)
    {
        return false;
    }
    return arr[i] <= h ? ok(i + 2, n, t - 1, h) : ok(i + 1, n, t, h);
}

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int l = 0, h = 1e9;
    while (l < h)
    {
        int m = l + (h - l) / 2;
        if (ok(0, n - ((k & 1) ^ 1), (k + 1) / 2, m) || ok(1, n - (k & 1), k / 2, m))
        {
            h = m;
        }
        else
        {
            l = m + 1;
        }
    }
    printf("%d\n", h);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    freopen("_error.txt", "w", stderr);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}