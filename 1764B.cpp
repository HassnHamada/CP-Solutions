#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 128, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

void run()
{
    int n, ans = 0, mx = 0;
    scanf("%d", &n);
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        mx = max(mx, v);
        ans = gcd(ans, v);
    }
    assert(mx % ans == 0);
    printf("%d\n", mx / ans);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}