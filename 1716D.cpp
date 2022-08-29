#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 20, L = 4, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int ans[N], prv[N], cur[N];

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    prv[0] = 1;
    for (int i = 0; i < n; i += k++)
    {
        for (int j = i + k; j <= n; j++)
        {
            (cur[j] = prv[j - k]) %= MOD;
            if (j - k >= i + k)
            {
                (cur[j] += cur[j - k]) %= MOD;
            }
            (ans[j] += cur[j]) %= MOD;
        }
        swap(cur, prv);
    }
    for (int i = 1; i <= n; i++)
    {
        std::printf("%d%c", ans[i], " \n"[i == n]);
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
