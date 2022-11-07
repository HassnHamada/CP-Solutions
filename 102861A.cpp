#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10, M = 100, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

double ans[N], acc[N];

void run()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; i++)
    {
        if (a)
        {
            ans[i] = 1.0 / (b - a + 1) * ((i - a >= 0 ? acc[i - a] : 0) - (i - b - 1 >= 0 ? acc[i - b - 1] : 0)) + 1;
        }
        else
        {
            ans[i] = 1.0 / (b - a) * ((b - a + 1) + acc[i - 1] - (i - b - 1 >= 0 ? acc[i - b - 1] : 0));
        }
        acc[i] = acc[i - 1] + ans[i];
    }
    printf("%lf\n", ans[n]);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}