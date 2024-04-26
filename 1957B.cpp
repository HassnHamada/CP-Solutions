#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> ans;
    if (n == 1)
    {
        ans.push_back(k);
    }
    else
    {
        int v = 31 - __builtin_clz(k);
        assert((1 << v) - 1 < k);
        assert((1 << (v + 1)) > k);
        ans.push_back((1 << v) - 1);
        ans.push_back(k - (1 << v) + 1);
        for (int i = 2; i < n; i++)
        {
            ans.push_back(0);
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", ans[i], " \n"[i == n - 1]);
    }
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