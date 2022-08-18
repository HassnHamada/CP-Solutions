#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 1e6 + 10, L = 1e6 + 10, Q = 448, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int vis[N], vid;

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    if (k & 1)
    {
        printf("YES\n");
        for (int i = 1; i <= n; i += 2)
        {
            printf("%d %d\n", i, i + 1);
        }
    }
    else
    {
        if (k % 4)
        {
            printf("YES\n");
            for (int i = 1; i <= n; i += 2)
            {
                if ((i - 1) % 4)
                {
                    printf("%d %d\n", i, i + 1);
                }
                else
                {
                    printf("%d %d\n", i + 1, i);
                }
            }
        }
        else
        {
            printf("NO\n");
        }
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
