#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 17, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int n;
int arr[N], val[N];

bool ok(int m)
{
    for (int i = 0; i < m; i++)
    {
        val[arr[i]] = 0;
    }
    bool ret = is_sorted(arr, arr + n, [](int i, int j)
                         { return val[i] < val[j]; });
    for (int i = 0; i < m; i++)
    {
        val[arr[i]] = arr[i];
    }
    return ret;
}

void run()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        val[arr[i]] = arr[i];
    }
    int l = 0, h = n;
    while (l < h)
    {
        int m = (h - l) / 2 + l;
        if (ok(m))
        {
            h = m;
        }
        else
        {
            l = m + 1;
        }
    }
    sort(arr, arr + l);
    int ans = unique(arr, arr + l) - arr;
    printf("%d\n", ans);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    iota(val, val + N, 0);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
