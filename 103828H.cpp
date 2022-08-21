#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 19, M = 6, MOD = 1e9 + 9, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    ll n;
    scanf("%lld", &n);
    if (n & 1)
    {
        printf("0\n");
    }
    else if (n % 4 == 0)
    {
        printf("%lld\n", n / 2 * (n / 2 - 1) - n / 4);
    }
    else
    {
        printf("%lld\n", n / 2 * (n / 2 - 1));
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