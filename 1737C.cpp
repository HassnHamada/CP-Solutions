#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e2 + 10, M = 128, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;


bool cen(int r1, int c1, int r2, int c2, int r3, int c3)
{
    return ((r1 == r2 && abs(c1 - c2) == 1) || (c1 == c2 && abs(r1 - r2) == 1)) &&
           ((r1 == r3 && abs(c1 - c3) == 1) || (c1 == c3 && abs(r1 - r3) == 1));
}

bool cor(int r1, int c1, int n)
{
    return (r1 == 1 && c1 == 1) ||
           (r1 == 1 && c1 == n) ||
           (r1 == n && c1 == 1) ||
           (r1 == n && c1 == n);
}

void run()
{
    int n;
    scanf("%d", &n);
    int r1, c1, r2, c2, r3, c3;
    scanf("%d%d%d%d%d%d", &r1, &c1, &r2, &c2, &r3, &c3);
    if (cen(r1, c1, r2, c2, r3, c3))
    {
    }
    else if (cen(r2, c2, r1, c1, r3, c3))
    {
        swap(r2, r1);
        swap(c2, c1);
    }
    else if (cen(r3, c3, r2, c2, r1, c1))
    {
        swap(r3, r1);
        swap(c3, c1);
    }
    else
    {
        assert(false);
    }
    int x, y;
    scanf("%d%d", &x, &y);
    if (cor(r1, c1, n))
    {
        if (x == r1 || y == c1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    else
    {
        if (((x ^ r1) & 1) == 0 || ((y ^ c1) & 1) == 0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
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