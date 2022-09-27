#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2e2 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char str[N];
int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    scanf("%s", str);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] = max(0, str[i] == 'L' ? (n - i - 1) - i : i - (n - i - 1));
        ans += str[i] == 'L' ? i : n - i - 1;
    }
    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < n; i++)
    {
        printf("%lld%c", ans += arr[i], " \n"[i + 1 == n]);
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