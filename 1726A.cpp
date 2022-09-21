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
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, arr[i] - arr[(i + 1) % n]);
    }
    int mx = max_element(arr, arr + n) - arr,
        mn = min_element(arr, arr + n) - arr;
    printf("%d\n", max({ans, arr[mx] - arr[0],
                        arr[n - 1] - arr[mn]}));
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