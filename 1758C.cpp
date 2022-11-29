#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 128, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int ans[N];

void move(int n, int x)
{
    for (int i = 2 * x; i < n; i += x)
    {
        if (n % i == 0)
        {
            swap(ans[i], ans[x]);
            x = i;
        }
    }
}

void run()
{
    int n, x;
    scanf("%d%d", &n, &x);
    if (n % x == 0)
    {
        iota(ans + 1, ans + n + 1, 1);
        swap(ans[1], ans[n]);
        if (x != n)
        {
            swap(ans[1], ans[x]);
            move(n, x);
        }
        for (int i = 1; i <= n; i++)
        {
            assert((i == 1 && ans[i] == x) || (i == n && ans[i] == 1) || (ans[i] % i == 0));
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
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}