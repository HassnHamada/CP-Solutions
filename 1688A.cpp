#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 20, M = 20, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
char str[N];
int ans[N], my_pow[N];

void run()
{
    int n;
    scanf("%d", &n);
    int z = __builtin_ctz(n);
    int p = __builtin_popcount(n);
    printf("%lld\n", (1ll << z) + (int)(p == 1) * (z ? 1 : 2));
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
