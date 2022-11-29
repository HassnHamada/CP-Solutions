#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 60, M = 1 << 8, MOD = 1e9, HV = 151, INF = 0x3f3f3f3f;

int trn[M][M], ans_[M][M], tem[M][M];

void solve(int n, int s, int b, int nb = 0)
{
    if (b == (1 << n) - 1)
    {
        trn[s][nb] = (trn[s][nb] + 1) % MOD;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if ((b >> i) & 1)
        {
            continue;
        }
        solve(n, s, b | (1 << i), nb);
        assert((nb & (1 << i)) == 0);
        solve(n, s, b | (1 << i), nb | (1 << i));
        if (i < n - 1 && (((b >> (i + 1)) & 1) == 0))
        {
            solve(n, s, b | (1 << i) | (1 << (i + 1)), nb);
        }
        break;
    }
}

void run()
{
    ll n, m;
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < (1 << n); i++)
    {
        solve(n, i, i);
    }
    ans_[0][0] = 1;
    while (m)
    {
        if (m & 1)
        {
            for (int j = 0; j < (1 << n); j++)
            {
                for (int k = 0; k < (1 << n); k++)
                {
                    tem[j][k] = 0;
                    for (int l = 0; l < (1 << n); l++)
                    {
                        tem[j][k] = (tem[j][k] + 1ll * ans_[j][l] * trn[l][k] % MOD) % MOD;
                    }
                }
            }
            swap(ans_, tem);
        }
        for (int j = 0; j < (1 << n); j++)
        {
            for (int k = 0; k < (1 << n); k++)
            {
                tem[j][k] = 0;
                for (int l = 0; l < (1 << n); l++)
                {
                    tem[j][k] = (tem[j][k] + 1ll * trn[j][l] * trn[l][k] % MOD) % MOD;
                }
            }
        }
        swap(trn, tem);
        m >>= 1;
    }
    printf("%d\n", ans_[0][0]);
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