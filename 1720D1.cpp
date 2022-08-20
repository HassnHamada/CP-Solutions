#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 10, M = 6, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], dp[N];
int n;

void run()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 0; i < n; i++)
    {
        int mx = 0;
        for (int j = max(0, i - 400); j < i; j++)
        {
            if ((arr[j] ^ i) < (arr[i] ^ j))
            {
                mx = max(mx, dp[j]);
            }
        }
        dp[i] = mx + 1;
    }
    printf("%d\n", *max_element(dp, dp + n));
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