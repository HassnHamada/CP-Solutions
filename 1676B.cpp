#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e1 + 10, M = 50, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int arr[N];

void run()
{
    int n, mn = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        mn = min(mn, arr[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += arr[i] - mn;
    }
    printf("%d\n", ans);
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