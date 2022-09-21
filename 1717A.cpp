#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10, M = 2e2 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

ll lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

void run()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int v = lcm(i, j) / gcd(i, j);
            // printf("%d\n", v);
            // if (v <= 3)
            // {
            //     printf("%d %d\n", i, j);
            //     ans += 2;
            //     break;
            // }
            ans += (v <= 3);
        }
    }
    assert(ans == n + n / 3 * 4 + (n / 2 - n / 3) * 2);
    printf("%d\n", ans);
    printf("%d\n", n + n / 3 * 4 + (n / 2 - n / 3) * 2);
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