#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++, n--)
    {
        printf("%d%c", n, " \n"[i == n]);
        if (i == n)
        {
            break;
        }
        printf("%d%c", i, " \n"[i == n - 1]);
    }
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}