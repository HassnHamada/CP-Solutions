#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 50, M = 9, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
char arr[N][M];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", (char *)(arr + i));
        // mn = min(mn, arr[i]);
    }
    int ans = INF;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int t = 0;
            for (int k = 0; k < m; k++)
            {
                t += abs(arr[i][k] - arr[j][k]);
            }
            ans = min(ans, t);
        }
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