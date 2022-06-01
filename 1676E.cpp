#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int arr[N];

void run()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    sort(arr, arr + n, greater<int>());
    for (int i = 1; i < n; i++)
    {
        arr[i] += arr[i - 1];
    }
    for (int i = 0, x; i < q; i++)
    {
        scanf("%d", &x);
        printf("%d\n", x > arr[n - 1] ? -1 : (int)(lower_bound(arr, arr + n, x) - arr + 1));
    }
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