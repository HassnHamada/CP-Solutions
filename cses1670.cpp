#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e1 + 10, M = 3, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    unordered_map<ll, int> dp((int)(1e6));
    dp[0x123456789] = 0;
    queue<ll> q;
    q.push(0x123456789);
    vector<int> vec = vector<int>({1, -1, 3, -3});
    vector<ll> msk = vector<ll>({
        0x00000000f,
        0x0000000f0,
        0x000000f00,
        0x00000f000,
        0x0000f0000,
        0x000f00000,
        0x00f000000,
        0x0f0000000,
        0xf00000000,
    });
    while (!q.empty())
    {
        ll f = q.front();
        q.pop();
        for (int i = 0; i < 9; i++)
        {
            for (auto &&j : vec)
            {
                int k = i + j;
                if (k < 0 || k >= 9)
                {
                    continue;
                }
                if (k / 3 == i / 3 || k % 3 == i % 3)
                {
                    ll a = (f & msk[i]) >> (4 * i),
                       b = (f & msk[k]) >> (4 * k),
                       c = (f & (~msk[i]) & (~msk[k])) | (a << (4 * k)) | (b << (4 * i));
                    if (dp.find(c) == dp.end())
                    {
                        dp[c] = dp[f] + 1;
                        q.push(c);
                    }
                }
            }
        }
    }

    ll inp = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0, v; j < 3; j++)
        {
            scanf("%d", &v);
            inp |= ((ll)(v) << ((8 - i * 3 - j) * 4));
        }
    }
    printf("%d\n", dp[inp]);
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}