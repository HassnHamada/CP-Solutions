#include <bits/stdc++.h>
// using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

char inp[N];
std::map<std::pair<int, int>, int> dp;

ll solve(int i, int c, int n)
{
    assert(abs(c) % 2 == 0);
    if ((inp[i] == '1' && c < 0) ||
        (inp[i] == '0' && c > 0))
    {
        return 0;
    }
    if (i == n - 1)
    {
        return 1;
    }
    std::pair<int, int> k = {i, c > 0 ? 1 : (c < 0 ? -1 : 0)};
    if (dp.find(k) == dp.end())
    {
        dp[k] = (solve(i + 1, c + 1 + (inp[i] == '1' ? 1 : -1), n) +
                 solve(i + 1, c - 1 + (inp[i] == '1' ? 1 : -1), n) + 1) %
                MOD;
    }
    return dp[k];
}

void run()
{
    int n;
    scanf("%d%s", &n, inp);
    dp.clear();
    printf("%lld\n", solve(0, 0, n));
}

int main()
{
    // freopen("_ok.txt", "w", stdout);
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