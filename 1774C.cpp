#include <bits/stdc++.h>
// using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 20, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

char win[N];
// int zer[N];

void run()
{
    int n;
    scanf("%d%s", &n, win);
    for (int i = 2, j = 0, k = -1; i <= n; i++)
    {
        if (win[i - 2] - '0' == k)
        {
            j++;
        }
        else
        {
            j = 1;
            k = win[i - 2] - '0';
        }
        printf("%d%c", i - j, " \n"[i == n]);
    }
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}