#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 1e5 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int n, arr[N], dp[N][M];

bool work(int c, int v)
{
    if (v == 0)
    {
        return true;
    }
    if (c == n || v < 0)
    {
        return false;
    }
    if (~dp[c][v])
    {
        return dp[c][v];
    }
    return (dp[c][v] = (work(c + 1, v - arr[c]) || work(c + 1, v)));
}

// 6
// 6 4 6 4 4 4

void run()
{
    int tot = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        tot += arr[i];
    }
    // cout << __builtin_ctz(32) << endl;
    memset(dp, -1, sizeof(dp));
    if (tot % 2 == 0 && work(0, tot / 2))
    {
        int g = INF;
        for (int i = 0; i < n; i++)
        {
            g = min(g, __builtin_ctz(arr[i]));
        }
        // int g = arr[0];
        // for (int i = 1; i < n; i++)
        // {
        //     g = __gcd(g, arr[i]);
        // }
        for (int i = 0; i < n; i++)
        {
            if ((arr[i] >> g) & 1)
            {
                printf("1\n%d\n", i + 1);
                break;
            }
        }
    }
    else
    {
        printf("0\n");
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