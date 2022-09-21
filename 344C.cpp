#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int N = 1e3 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    ll a, b, ans = 0;
    scanf("%lld%lld", &a, &b);
    while (a && b)
    {
        if (a > b)
        {
            ans += a / b;
            a %= b;
        }
        else if (b > a)
        {
            ans += b / a;
            b %= a;
        }
        else
        {
            assert(a == 1 && b == 1);
            ans += 1;
            break;
        }
    }
    printf("%lld\n", ans);
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