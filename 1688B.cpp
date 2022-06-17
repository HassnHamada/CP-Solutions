#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int arr[M];

void run()
{
    memset(arr, 0, sizeof(arr));
    int n;
    scanf("%d", &n);
    // int z = __builtin_ctz(n);
    // int p = __builtin_popcount(n);

    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        arr[__builtin_ctz(v)]++;
    }
    int mn;
    for (int i = 0; i < M; i++)
    {
        mn = i;
        if (arr[mn])
        {
            break;
        }
        // cout << arr[i] << " ";
    }
    printf("%d\n", mn ? n - 1 + mn : n - arr[0]);
    // int ans = mn + n - arr[0];
    // cout << endl;
    // ll ans = 0;
    // while (true)
    // {
    //     int ii = 0, jj = M - 1;
    //     while (ii <= jj && arr[ii] == 0)
    //     {
    //         ii++;
    //     }
    //     while (ii <= jj && arr[jj] == 0)
    //     {
    //         jj--;
    //     }
    //     if (ii == jj)
    //     {
    //         ans += ii * arr[ii];
    //         break;
    //     }
    //     if (ii == 0)
    //     {
    //         if (arr[ii] <= arr[jj])
    //         {
    //             ans += arr[ii];
    //             arr[jj] -= arr[ii];
    //             arr[ii] = 0;
    //         }
    //         else
    //         {
    //             ans += (1ll << ii) * arr[jj];
    //             arr[ii] -= arr[jj];
    //             arr[jj] = 0;
    //         }
    //     }
    //     else
    //     {
    //         if (arr[ii] <= arr[jj])
    //         {
    //             ans += (1ll << ii) * arr[ii];
    //             arr[jj] -= arr[ii];
    //             arr[ii] = 0;
    //         }
    //         else
    //         {
    //             ans += (1ll << ii) * arr[jj];
    //             arr[ii] -= arr[jj];
    //             arr[jj] = 0;
    //         }
    //     }
    // }
    // printf("%lld\n", ans);
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
