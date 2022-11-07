#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 448, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    int v1 = 0, v2 = 0;
    while ((x & 1) == 0)
    {
        x >>= 1;
        v1++;
    }
    while ((y & 1) == 0)
    {
        y >>= 1;
        v2++;
    }
    assert(v1 == v2);
    assert(v1 < n);
    printf("%d\n", n - v1 - 1);
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