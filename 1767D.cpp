#include <bits/stdc++.h>
// using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 20, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

char win[M];

void run()
{
    int n;
    scanf("%d%s", &n, win);
    int z = std::count(win, win + n, '0'), o = n - z;
    for (int i = 1 << o, m = (1 << n) - (1 << z) + 1; i <= m; i++)
    {
        printf("%d%c", i, " \n"[i == m]);
    }
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