#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e3 + 10, M = 31, L = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char str[N][N];

void run()
{
    int n, c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", (char *)(str + i));
        c += count((char *)(str + i), (char *)(str + i) + n, '1');
    }
    int ans = INF;
    for (int i = 0; i < n; i++)
    {
        int tem = 0;
        for (int j = 0; j < n; j++)
        {
            tem += str[j][(j + i) % n] == '0' ? 1 : 0;
        }
        ans = min(ans, 2 * tem + c - n);
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
