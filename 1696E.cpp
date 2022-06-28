#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 5e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int arr[N], tem[N], aaa[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", aaa + i);
    }
    arr[0] = 1;
    int ans = aaa[0];
    for (int i = 0; i < n; i++)
    {
        // cout << ans << " ";
        for (int j = 0; j < aaa[i + 1]; j++)
        {
            tem[j] = 0;
            for (int k = 0; k <= j; k++)
            {
                tem[j] = (1ll * tem[j] + arr[k]) % MOD;
            }
        }
        swap(arr, tem);
        // for (int j = 0; j < aaa[i + 1]; j++)
        // {
        //     cout << arr[j] << " ";
        // }
        // cout << endl;
        for (int j = 0; j < aaa[i + 1]; j++)
        {
            ans = (ans + 1ll * arr[j] * (aaa[i + 1] - j)) % MOD;
        }
    }
    printf("%d\n", ans);
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
