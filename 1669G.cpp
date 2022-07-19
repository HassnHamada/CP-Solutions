#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e1 + 10, M = 31, L = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char grd[N][N];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", (char *)(grd + i));
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = n - 1, k = n - 1; ~j; j--)
        {
            if (grd[j][i] == '*')
            {
                swap(grd[j][i], grd[k--][i]);
            }
            else if (grd[j][i] == 'o')
            {
                k = j - 1;
            }
            else if (grd[j][i] == '.')
            {
                continue;
            }
            else
            {
                assert(false);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", (char *)(grd + i));
    }
    printf("\n");
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
