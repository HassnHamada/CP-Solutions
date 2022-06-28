#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 448, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
char str[N];
int ooo[N], zzz[N];

void run()
{
    scanf("%s", str);
    int n = strlen(str);
    for (int i = 1; i <= n; i++)
    {
        ooo[i] = ooo[i - 1] + (int)(str[i - 1] == '1');
        zzz[i] = zzz[i - 1] + (int)(str[i - 1] == '0');
    }
    int ans = zzz[n];
    for (int i = 0; i <= n; i++)
    {
        int l = 0, h = ooo[n] - ooo[i];
        while (l <= h)
        {
            int m = (h - l) / 2 + l;
            int j = lower_bound(ooo, ooo + n + 1, ooo[n] - m) - ooo;
            int o = ooo[i] + m, z = zzz[j] - zzz[i];
            ans = min(ans, max(o, z));
            if (o == z)
            {
                break;
            }
            else if (o < z)
            {
                l = m + 1;
            }
            else
            {
                h = m - 1;
            }
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