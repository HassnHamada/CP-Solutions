#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 1e6 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], dp[N];

void run()
{
    int n, s, l;
    scanf("%d%d%d", &n, &s, &l);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    memset(dp, -1, sizeof(dp[0]) * n);
    multiset<int> mn_mx(arr + n - l + 1, arr + n), ans;
    for (int i = n - l, k = n; i >= 0; i--)
    {
        mn_mx.insert(arr[i]);
        while (*mn_mx.rbegin() - *mn_mx.begin() > s)
        {
            if (ans.find(dp[k]) != ans.end())
            {
                ans.erase(ans.find(dp[k]));
            }
            assert(mn_mx.find(arr[--k]) != mn_mx.end());
            mn_mx.erase(mn_mx.find(arr[k]));
        }
        assert(mn_mx.size() >= 1);
        if (k - i >= l && ~dp[i + l])
        {
            ans.insert(dp[i + l]);
        }
        if (!ans.empty())
        {
            dp[i] = *ans.begin() + 1;
        }
    }
    printf("%d\n", dp[0]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}