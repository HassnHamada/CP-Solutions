#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int arr[N];
map<pair<int, int>, pair<int, int>> dp;
int n, q;
char ans[N];

int solve(int cn, int cq, int c = 0)
{
    cout << cn << " " << cq << " " << c << endl;
    if (cq == 0)
    {
        while (cn < n)
        {
            ans[cn++] = '0';
        }
        ans[cn] = '\0';
        return c;
    }
    if (cq >= n - cn)
    {
        c += n - cn;
        while (cn < n)
        {
            ans[cn++] = '1';
        }
        ans[cn] = '\0';
        return c;
    }
    if (dp.find({cn, cq}) == dp.end())
    {
        int ii = 0;
        while (cn + ii < n && arr[cn + ii] <= cq)
        {
            ans[cn + ii] = '1';
            ii += 1;
        }
        // ans[cn + ii] = '1';
        int a = solve(cn + ii + 1, cq - 1, c + ii + 1);
        int b = solve(cn + ii + 1, cq, c + ii);
        if (a > b)
        {
            dp.insert({{cn, cq}, {ii, 1}});
            ans[cn + ii] = '1';
            // return solve(cn + ii + 1, cq - 1, c + ii + 1);
            return a;
        }
        dp.insert({{cn, cq}, {ii, 0}});
        ans[cn + ii] = '0';
        return b;
    }
    int w = dp[{cn, cq}].first, v = dp[{cn, cq}].second, ii = 0;
    while (ii < w)
    {
        ans[cn + (ii++)] = '1';
    }
    ans[cn + ii] = v ? '1' : '0';
    return solve(cn + w + 1, cq - v, c + w + v);
}

void run()
{
    dp.clear();
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    assert(solve(0, q) != INT32_MIN);
    printf("%s\n", ans);
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