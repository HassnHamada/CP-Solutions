#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e3 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char bs[N], cp[N];

void run()
{
    int n;
    scanf("%d%s", &n, bs);
    auto ok = [&n](int k)
    {
        assert(k);
        strcpy(cp, bs);
        for (int i = 0; i <= n - k; i++)
        {
            if (cp[i] == '0')
            {
                for (int j = 0; j < k; j++)
                {
                    cp[i + j] ^= 1;
                }
            }
        }
        return all_of(cp + n - k, cp + n, [](int i)
                      { return i == '1'; });
    };
    int ans = 0;
    for (int i = 31 - __builtin_clz(n); ~i; i--)
    {
        if (ok(ans + (1 << i)))
        {
            ans += (1 << i);
        }
    }
    printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}