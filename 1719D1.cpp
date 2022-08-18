#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e3 + 10, M = 15, L = 1e2 + 10, Q = 448, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];
int acc[N][M];

bool equ(int jj)
{
    int mx = *max_element((int *)(acc[jj]), (int *)(acc[jj]) + M);
    for (int i = 0; i < M; i++)
    {
        if (acc[jj][i] == 0)
        {
            continue;
        }
        if (acc[jj][i] != mx)
        {
            return false;
        }
    }
    return true;
}

int n;
int dp[M][M][N];

int solve(int ii = 1, int jj = 1, int p = 0)
{
    if (ii == n + 1)
    {
        return 0;
    }
    int ret = dp[ii][jj][p];
    if (~ret)
    {
        return ret;
    }
    // cout << ii << " " << jj << endl;
    while (jj <= n)
    {
        for (int j = 0; j < M; j++)
        {
            acc[jj][j] = acc[jj - 1][j];
            acc[jj][j] += ((arr[jj] >> j) & 1);
        }
        if (!equ(jj))
        {
            for (int j = 0; j < M; j++)
            {
                acc[jj][j] = ((arr[jj] >> j) & 1);
            }
            ret = solve(jj, jj + 1, arr[jj]) + (arr[ii] ? (jj - ii + 1) / 2 : 0);
            arr[jj] ^= arr[jj - 1];
            for (int j = 0; j < M; j++)
            {
                acc[jj][j] = ((arr[jj] >> j) & 1);
            }
            ret = min(ret, solve(jj, jj + 1, arr[jj]) + (arr[ii] ? (jj - ii + 2) / 2 : 0));
            return ret;
        }
        jj += 1;
    }
    return ret = (arr[ii] ? (jj - ii + 1) / 2 : 0);
}

void run()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
        // for (int j = 0; j < M; j++)
        // {
        //     acc[i][j] = acc[i - 1][j];
        //     acc[i][j] += ((arr[i] >> j) & 1);
        // }
    }
    // int ans = 0, ii = 0, jj = 0;
    // while (jj < n)
    // {
    //     jj += 1;
    //     assert(ii <= jj);
    //     for (int j = 0; j < M; j++)
    //     {
    //         acc[jj][j] = acc[jj - 1][j];
    //         acc[jj][j] += ((arr[jj] >> j) & 1);
    //     }
    //     if (!equ(jj))
    //     {
    //         cout << ii << " " << jj << endl;
    //         ans += (jj - ii + 1) / 2;
    //         ii = jj - 1;
    //         arr[jj] ^= arr[jj - 1];
    //         for (int j = 0; j < M; j++)
    //         {
    //             acc[jj][j] = ((arr[jj] >> j) & 1);
    //         }
    //     }
    // }
    // if (arr[n])
    // {
    //     ans += (jj - ii + 1) / 2;
    // }
    // printf("%d\n", ans);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve());
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
