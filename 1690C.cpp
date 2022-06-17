#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
// int sss[N], fff[N], ans[N];
int sss[N], fff[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", sss + i);
    }
    for (int i = 0, c = 0; i < n; i++)
    {
        c = max(c, sss[i]);
        scanf("%d", fff + i);
        printf("%d%c", fff[i] - c, " \n"[i + 1 == n]);
        c = fff[i];
    }
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
