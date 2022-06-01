#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e4 + 10, M = 50, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
// int n, k, dp[N][M], arr[N];

void run()
{
    int n, v = 0;
    scanf("%d", &n);
    for (int i = 0; i < 3; i++)
    {
        v += n % 10;
        n /= 10;
    }
    for (int i = 0; i < 3; i++)
    {
        v -= n % 10;
        n /= 10;
    }
    printf(v ? "NO\n" : "YES\n");
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