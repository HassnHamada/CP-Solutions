#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e1 + 10, M = 1 << 11, L = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int ans[N][N];
int n = N, m = N;

void solve(int i, int j, int p)
{
    if (i == n || j == m)
    {
        return;
    }
    ans[i][j] = ans[i + 1][j + 1] = p;
    ans[i + 1][j] = ans[i][j + 1] = p ^ 1;
    if (j == 0)
    {
        solve(i + 2, j, p ^ 1);
    }
    solve(i, j + 2, p ^ 1);
}

void run()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d%c", ans[i][j], " \n"[j + 1 == m]);
        }
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    solve(0, 0, 0);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}