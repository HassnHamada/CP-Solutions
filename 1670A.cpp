#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int arr[N];

void run()
{
    int n, nv = 0;
    scanf("%d\r\n", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        nv += arr[i] < 0;
        arr[i] = abs(arr[i]);
    }
    bool ok = true;
    for (int i = 1; i < nv; i++)
    {
        ok &= arr[i] <= arr[i - 1];
    }
    for (int i = nv + 1; i < n; i++)
    {
        ok &= arr[i] >= arr[i - 1];
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