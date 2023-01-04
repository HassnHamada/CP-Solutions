#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e3 + 10, M = 1 << 12, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

char inp[N][N], row[N], col[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", (char *)(inp + i));
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            row[i] += inp[i][j] == '1';
            col[i] += inp[j][i] == '1';
        }
        ans += row[i] == n + col[i] == n;
    }
    cout << ans << endl;
    // printf("%d\n", dis[v] == INF ? -1 : dis[v]);
}

int main()
{
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}