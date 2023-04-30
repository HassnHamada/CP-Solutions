#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int ans[M];

int solve(int c, int n, int r, int k, int v)
{
    if (c == n)
    {
        return k;
    }
    if (k < r + 1)
    {
        int s = r * (r + 1) + 1;
        for (int i = 0; i < k; i++)
        {
            s -= ans[i];
        }
        ans[c] = -s;
        for (int i = r + 1; i < n; i++)
        {
            ans[i] = -999;
        }
        return 0;
    }
    ans[c] = v;
    return solve(c + 1, n, r + 1, k - r - 1, v + 2);
}

int count_(int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += ans[j];
            assert(sum != 0);
            cnt += sum > 0;
        }
    }
    return cnt;
}

void run()
{
    memset(ans, 0, sizeof(ans));
    int n, k;
    scanf("%d%d", &n, &k);
    solve(0, n, 0, k, 2);
    assert(count_(n) == k);
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", ans[i], " \n"[i + 1 == n]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}