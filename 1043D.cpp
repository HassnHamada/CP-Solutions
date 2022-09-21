#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[M][N], ind[M][N];
int n, m;

bool ok(int ii, int jj)
{
    if (ind[0][ii] + jj == n)
    {
        return false;
    }
    for (int i = 1; i < m; i++)
    {
        if (arr[0][ind[0][ii] + jj] != arr[i][ind[i][ii] + jj])
        {
            return false;
        }
    }
    return true;
}

void run()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", (int *)(arr + i) + j);
            ind[i][arr[i][j]] = j;
        }
    }
    ll ans = 0;
    for (int i = 0, j = 1; i < n; i += j, j = 1)
    {
        while (ok(arr[0][i], j))
        {
            j += 1;
        }
        ans += 1ll * j * (j + 1) / 2;
    }
    printf("%lld\n", ans);
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