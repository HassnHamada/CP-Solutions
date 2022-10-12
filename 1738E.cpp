#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1e5 + 10, M = 2, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int inp[N], dp[N], n;

vector<int> cut;

int solve(int ii)
{
    if (ii == n)
    {
        int sz = cut.size();
        for (int i = 0; i < sz / 2; i++)
        {
            if (cut[i] != cut[sz - i - 1])
            {
                return false;
            }
        }
        return true;
    }
    int &ret = dp[ii];
    if (~ret)
    {
        return ret;
    }
    cut.push_back(inp[ii]);
    ret = solve(ii + 1);
    cut.pop_back();
    if (!cut.empty())
    {
        cut.back() += inp[ii];
        ret += solve(ii + 1);
        cut.back() -= inp[ii];
    }
    return ret;
}

void run()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", inp + i);
    }
    memset(dp, -1, sizeof(dp[0]) * n);
    printf("%d\n", solve(0));
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