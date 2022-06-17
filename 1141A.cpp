#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
ll arr[N];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int ans = -1;
    if (m % n == 0)
    {
        ans = 0;
        n = m / n;
        while (n % 2 == 0)
        {
            n /= 2;
            ans += 1;
        }
        while (n % 3 == 0)
        {
            n /= 3;
            ans += 1;
        }
        if (n != 1)
        {
            ans = -1;
        }
    }
    printf("%d\n", ans);
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
