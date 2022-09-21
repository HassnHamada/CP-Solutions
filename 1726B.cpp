#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int ans[N];

bool solve(int n, int m)
{
    if (m < n || (n % 2 == 0 && m % 2 == 1))
    {
        return false;
    }
    if (n & 1)
    {
        for (int i = 0; i < n - 1; i++)
        {
            ans[i] = 1;
        }
        ans[n - 1] = m - n + 1;
    }
    else
    {
        for (int i = 0; i < n - 2; i++)
        {
            ans[i] = 1;
        }
        ans[n - 1] = ans[n - 2] = (m - n + 2) / 2;
    }
    return true;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if (solve(n, m))
    {
        printf("Yes\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d%c", ans[i], " \n"[i + 1 == n]);
        }
    }
    else
    {
        printf("No\n");
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}