#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 30, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int idx[N];

void run()
{
    memset(idx, -1, sizeof(idx));
    int n;
    scanf("%d", &n);
    for (int i = 1, v; i <= n; i++)
    {
        scanf("%d", &v);
        idx[v] = i;
    }
    int ans = -1;
    for (int i = 1; i < N; i++)
    {
        if (idx[i] == -1)
        {
            continue;
        }
        for (int j = i; j < N; j++)
        {
            if (idx[j] == -1)
            {
                continue;
            }
            // cout << i << " " << j << " " << gcd(i, j) << endl;
            if (gcd(i, j) == 1)
            {
                ans = max(ans, idx[i] + idx[j]);
            }
        }
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
