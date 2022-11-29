#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 128, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int ans[N], usd[N], uid;

bool solve(int n, int mx)
{
    if (n == mx)
    {
        return true;
    }
    for (int i = n; i <= mx; i += n)
    {
        if (usd[i] == uid)
        {
            continue;
        }
        ans[n] = i;
        usd[i] = uid;
        if (solve(n + 1, mx))
        {
            return true;
        }
        usd[i] = 0;
    }
    return false;
}

void run()
{
    int n, x;
    scanf("%d%d", &n, &x);
    ans[1] = x;
    ans[n] = 1;
    usd[1] = usd[x] = ++uid;
    if (solve(2, n))
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d%c", ans[i], " \n"[i == n]);
        }
    }
    else
    {
        printf("-1\n");
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}