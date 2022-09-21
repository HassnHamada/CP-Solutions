#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int ans[N];

void asd(int s, int n)
{
    for (int i = 0; i < n; i++)
    {
        ans[4 * i + s] = 4 * (i + 5);
        ans[4 * i + s + 1] = 4 * (i + 5) + 1;
        ans[4 * i + s + 2] = 4 * (i + 5) + 3;
        ans[4 * i + s + 3] = 4 * (i + 5) + 2;
    }
}

void run()
{
    int n;
    scanf("%d", &n);
    if (n % 4 == 0)
    {
        asd(0, n / 4);
    }
    else if (n % 4 == 1)
    {
        ans[0] = 0;
        asd(1, n / 4);
    }
    else if (n % 4 == 2)
    {
        ans[0] = 0;
        ans[1] = 1;
        ans[2] = 8;
        ans[3] = 2;
        ans[4] = 15;
        ans[5] = 4;
        asd(6, n / 4 - 1);
    }
    else if (n % 4 == 3)
    {
        ans[0] = 2;
        ans[1] = 1;
        ans[2] = 3;
        asd(3, n / 4);
    }
    else
    {
        assert(false);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", ans[i], " \n"[i + 1 == n]);
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