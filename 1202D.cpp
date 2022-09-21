#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 448, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char ans[N];
int sz;

int bs(int n)
{
    int l = 2, h = 32000;
    while (l < h)
    {
        int m = (h - l + 1) / 2 + l;
        if (m * (m - 1) / 2 <= n)
        {
            l = m;
        }
        else
        {
            h = m - 1;
        }
    }
    return l;
}

int solve(int n)
{

    if (n == 0)
    {
        ans[sz++] = '7';
        return 0;
    }
    int a = bs(n);
    int b = n / (a * (a - 1) / 2);
    for (int i = solve(n % (a * (a - 1) / 2)); i < a; i++)
    {
        ans[sz++] = '3';
    }
    for (int i = 0; i < b; i++)
    {
        ans[sz++] = '1';
    }
    return a;
}

void run()
{
    int n;
    scanf("%d", &n);
    sz = 0;
    solve(n);
    ans[sz] = '\0';
    reverse(ans, ans + sz);
    printf("%s\n", ans);
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