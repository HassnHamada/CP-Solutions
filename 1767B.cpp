#include <bits/stdc++.h>
// using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 3, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int inp[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", inp + i);
    }
    std::sort(inp + 1, inp + n);
    ll ans = inp[0];
    for (int i = 1; i < n; i++)
    {
        if (ans >= inp[i])
        {
            continue;
        }
        ll inc = (inp[i] - ans + 1) >> 1;
        // std::cout << ans << " " << inp[i] << " " << inc << std::endl;
        ans += inc;
        // assert(inp[i] - inc >= 0);
        // assert(ans >= inp[i] - inc);
        // assert(ans - 1 < inp[i] - inc + 1);
    }
    printf("%lld\n", ans);
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}