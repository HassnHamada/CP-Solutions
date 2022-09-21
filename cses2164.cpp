#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 18, M = 448, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int ans(int n, int k)
{
    if (n == 1)
    {
        return 1;
    }
    if (k <= (n + 1) / 2)
    {
        if (2 * k > n)
        {
            return 2 * k % n;
        }
        else
        {
            return 2 * k;
        }
    }

    int res = ans(n >> 1, k - (n + 1) / 2);
    if (n & 1)
    {
        return 2 * res + 1;
    }
    else
    {
        return 2 * res - 1;
    }
}

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%d\n", ans(n, k));
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}