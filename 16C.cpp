#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int a, b, x, y;
    scanf("%d%d%d%d", &a, &b, &x, &y);
    int g = __gcd(x, y);
    x /= g;
    y /= g;
    int l = min(a / x, b / y);
    printf("%d %d\n", l * x, l * y);
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