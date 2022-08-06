#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 20, L = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

// char sss[N], ttt[N];
// int n, dp[N][L];

void run()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", n == 1 ? 2 : (n + 2) / 3);
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
