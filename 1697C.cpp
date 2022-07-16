#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 3, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int n, bbb[N];
char sss[N], ttt[N];

void run()
{
    scanf("%d%s%s", &n, sss, ttt);
    // printf("%d\n%s\n%s", n, sss, ttt);
    bool ok = count(sss, sss + n, 'a') == count(ttt, ttt + n, 'a') &&
              count(sss, sss + n, 'b') == count(ttt, ttt + n, 'b') &&
              count(sss, sss + n, 'c') == count(ttt, ttt + n, 'c');
    for (int i = 0; i < n; i++)
    {
        bbb[i] += (sss[i] == 'b' ? 1 : 0);
    }
    for (int i = 0, a = 0, b = 0, c = 0, rb = 0; ok && i < n; i++)
    {
        b += (sss[i] == 'b' ? 1 : 0);
        ok = b >= a;
        a += (sss[i] == 'a' ? 1 : 0) + (ttt[i] == 'a' ? -1 : 0);
        rb += (sss[n - i - 1] == 'b' ? 1 : 0);
        ok = rb >= c;
        c += (sss[n - i - 1] == 'c' ? 1 : 0) + (ttt[n - i - 1] == 'c' ? -1 : 0);
    }
    printf(ok ? "YES\n" : "NO\n");
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}
