#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 20, L = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int st[N][M], lg[N];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", (int *)(st + i));
    }
    for (int i = 2; i <= m; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 1; i <= lg[m]; i++)
    {
        for (int j = 0; j + (1 << (i - 1)) < m; j++)
        {
            st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
        }
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int xs, ys, xe, ye, k;
        scanf("%d%d%d%d%d", &xs, &ys, &xe, &ye, &k);
        xs += (n - xs) / k * k;
        xe += (n - xe) / k * k;
        if (ye < ys)
        {
            swap(ye, ys);
        }
        bool ok = xs == xe && (ye - ys) % k == 0 && xs > max(st[ys - 1][lg[ye - ys + 1]], st[ye - (1 << lg[ye - ys + 1])][lg[ye - ys + 1]]);
        printf(ok ? "YES\n" : "NO\n");
    }
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
