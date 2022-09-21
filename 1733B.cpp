#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

const int N = 1e5 + 10, M = 26, L = 4, MOD = 9, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    if (x + y != 0 && ((x == 0 && (n - 1) % y == 0) || (y == 0 && (n - 1) % x == 0)))
    {
        if (x == 0)
        {
            swap(x, y);
        }
        assert(x);
        for (int i = 1, p = 1; i < n; i++)
        {
            printf("%d%c", p, " \n"[i == n - 1]);
            if (i % x == 0)
            {
                p = i + 2;
            }
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