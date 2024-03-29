#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e3 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int ans = INF;
    for (int i = 1; i <= arr[0]; i++)
    {
        int cmx = -INF;
        for (int j = 0; j < n; j++)
        {
            int p = min(k, arr[j] / i);
            cmx = max(cmx, arr[j] / p);
        }
        ans = min(ans, cmx - i);
    }
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