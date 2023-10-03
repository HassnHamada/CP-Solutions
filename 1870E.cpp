#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#endif
#include <stdio.h>
#include <set>
#include <assert.h>
#include <string.h>
#include <bitset>
#include <numeric>
using namespace std;
typedef long long ll;

const int N = 5e3 + 1, M = 8192;

int arr[N], mex[N][N], dp[N][M];
bitset<N> in;

// int calc(int i, int n, int r = 0)
// {
//     assert(r < M);
//     if (~dp[i][r])
//     {
//         return dp[i][r];
//     }
//     int ret = r;
//     for (int j = i; j < n; j++)
//     {
//         ret = max(ret, calc(j + 1, n, r ^ mex[i][j]));
//         ret = max(ret, calc(j + 1, n, r));
//     }
//     return dp[i][r] = ret;
// }

void run()
{
    // printf("%f\n", (sizeof(arr) + sizeof(mex) + sizeof(dp) + sizeof(in)) / 1048576.0);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 0; i <= n; i++)
    {
        // memset((int *)(dp + i), -1, sizeof(dp[0][0]) * M);
        iota((int *)(dp + i), (int *)(dp + i) + M, 0);
    }
    // iota((int *)(dp + n), (int *)(dp + n) + M, 0);
    for (int i = 0; i < n; i++)
    {
        in.reset();
        for (int j = i, v = 0; j < n; j++)
        {
            in.set(arr[j]);
            while (in[v])
            {
                v++;
            }
            mex[i][j] = v;
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         printf("x\t");
    //     }
    //     for (int j = i; j < n; j++)
    //     {
    //         printf("%d\t", mex[i][j]);
    //     }
    //     printf("\n");
    // }
    for (int i = n - 1; ~i; i--)
    {
        for (int j = 0; j < n || j & n; j++)
        {
            for (int k = i; k < n; k++)
            {
                dp[i][j] = max({dp[i][j], dp[k + 1][j ^ mex[i][k]], dp[k + 1][j]});
            }
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j < n || j & n; j++)
    //     {
    //         printf("%d\t", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%d\n", dp[0][0]);
    // printf("%d\n", calc(0, n));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}