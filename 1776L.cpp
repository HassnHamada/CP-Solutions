#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 1e6 + 10, Q = 548, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char str[N];

void run()
{
    int n, q;
    scanf("%d%s%d", &n, str, &q);
    int pos = count(str, str + n, '+'),
        neg = n - pos;
    for (int i = 0, a, b; i < q; i++)
    {
        scanf("%d%d", &a, &b);
        if (a < b)
        {
            swap(a, b);
        }
        ll c = lcm((ll)a, b);
        assert(a >= b);
        assert(c % a == 0);
        assert(c % b == 0);
        ll big = pos, sml = neg;
        if (big < sml)
        {
            swap(big, sml);
        }
        while (big != sml && a != b)
        {
            // cout << big << " " << sml << endl;
            assert(big > sml);
            // int dif = big - sml;
            ll rm = (big - sml + (c / b - c / a - 1)) / (c / b - c / a);
            // cout << rm << endl;
            // cout << c / b * rm << " " << c / a * rm << endl;
            big -= c / b * rm;
            sml -= c / a * rm;
            assert(big <= sml);
            swap(big, sml);
            if (sml <= 0)
            {
                break;
            }
            // big -= c / b * x;
            // sml -= c / a * x;
            // big - c / b * x <= sml - c / a * x
            // big - sml <= c / b * x - c / a * x
            // (big - sml) / (c / b - c / a) <= x
        }
        printf(sml >= 0 && big == sml ? "YES\n" : "NO\n");
    }
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
