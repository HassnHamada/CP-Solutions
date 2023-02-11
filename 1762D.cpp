#include <bits/stdc++.h>
// using namespace std;
typedef long long ll;

const int N = 2e4 + 10, M = 2, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int ask(int i, int j)
{
    printf("? %d %d\n", i, j);
    fflush(stdout);
    int r;
    scanf("%d", &r);
    if (r == -1)
    {
        exit(1);
    }
    return r;
}

int ans(int i, int j)
{
    printf("! %d %d\n", i, j);
    fflush(stdout);
    int r;
    scanf("%d", &r);
    if (r == -1)
    {
        exit(1);
    }
    return r;
}

void run()
{
    int n;
    scanf("%d", &n);
    int a = 1, b = 2, g = ask(1, 2);
    for (int i = 3; i <= n; i++)
    {
        int g1 = ask(a, i), g2 = ask(b, i);
        if (g >= std::max(g1, g2))
        {
            continue;
        }
        if (g1 >= std::max(g, g2))
        {
            b = i;
            g = g1;
        }
        else
        {
            assert(g2 > std::max(g, g1));
            a = i;
            g = g2;
        }
    }
    ans(a, b);
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