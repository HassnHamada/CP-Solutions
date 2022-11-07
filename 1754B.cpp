#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1e3 + 10, M = 2, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int ans[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = n / 2 + 1, j = i; i <= n; i++)
    {
        ans[2 * (i - j)] = i;
        ans[2 * (i - j) + 1] = i - j + 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", ans[i], " \n"[i + 1 == n]);
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