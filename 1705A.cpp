#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < 2 * n; i++)
    {
        scanf("%d", arr + i);
    }
    sort(arr, arr + 2 * n);
    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        ok = ok && arr[i] + x <= arr[i + n];
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