#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 30, MOD = 998244353, HV = 151;
int aaa[N], bbb[N], ind[N], dp[N];
int n, s;

int solve(int ci)
{
    if (ci == n)
    {
        return 1;
    }
    if (~dp[ci])
    {
        return dp[ci];
    }
    cout << ci << " " << aaa[ci] << endl;
    int ret = 0;
    // if (aaa[ci] <= ci && (aaa[ci] == bbb[ci] || bbb[ci] == -1))
    // {
    //     ret = solve(ci + 1);
    // }
    // else if (bbb[ci] == -1)
    if (bbb[ci] == -1)
    {
        for (int i = ci + 1; i <= min(ci + 1 + s, n); i++)
        {
            if (ind[i] < ci)
            {
                continue;
            }
            for (int j = i; j <= min(ci + 1 + s, n); j++)
            {
                if (ind[j] < ci)
                {
                    continue;
                }
                swap(aaa[ind[i]], aaa[ind[j]]);
                swap(ind[i], ind[j]);
                ret = (1ll * ret + solve(ci + 1)) % MOD;
                swap(aaa[ind[i]], aaa[ind[j]]);
                swap(ind[i], ind[j]);
            }
        }
    }
    else
    // else if (bbb[ci] >= aaa[ci] && bbb[ci] - aaa[ci] <= s)
    {
        // cout << "in B " << bbb[ci] << endl;
        swap(aaa[ci], aaa[ind[bbb[ci]]]);
        swap(ind[aaa[ci]], ind[bbb[ci]]);
        ret = solve(ci + 1);
        swap(aaa[ci], aaa[ind[bbb[ci]]]);
        swap(ind[aaa[ci]], ind[bbb[ci]]);
    }
    cout << "out" << endl;
    return dp[ci] = ret;
}

void run()
{
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", aaa + i);
        ind[aaa[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", bbb + i);
    }
    // solve(0);
    memset(dp, -1, sizeof(dp[0]) * n);
    printf("%d\n", solve(0));
    // printf(ok ? "YES\n" : "NO\n");
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