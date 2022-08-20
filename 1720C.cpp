#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e2 + 10, M = 6, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char mat[N][N];

int n, m;

bool calc(int ii, int jj)
{
    for (int i = ii - 1; i <= ii + 1; i++)
    {
        if (i < 0 || i >= n)
        {
            continue;
        }
        for (int j = jj - 1; j <= jj + 1; j++)
        {
            if (j < 0 || j >= m || (i == ii && j == jj))
            {
                continue;
            }
            if (mat[i][j] == '0')
            {
                return true;
            }
        }
    }
    return false;
}

void run()
{
    scanf("%d%d", &n, &m);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", (char *)(mat + i));
        ans += count((char *)(mat + i), (char *)(mat + i) + m, '1');
    }
    if (ans == n * m)
    {
        ans -= 2;
    }
    else
    {
        bool dec = true;
        for (int i = 0; dec && i < n; i++)
        {
            for (int j = 0; dec && j < m; j++)
            {
                if (mat[i][j] == '0' && calc(i, j))
                {
                    dec = false;
                }
            }
        }
        if (dec)
        {
            ans -= 1;
        }
    }
    assert(ans >= 0);
    printf("%d\n", ans);
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