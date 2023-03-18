#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 1e6 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    bool ok = true;
    sort(arr, arr + n);
    for (int i = 2; i < n; i++)
    {
        arr[i] = min(arr[i], arr[0] + arr[1]);
        ok = ok && arr[i] <= d;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
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