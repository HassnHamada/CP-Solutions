#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;

ll arr[N];
int n;

ll solve(ll a = 0, ll b = 0, int i = 0)
{
    for (; i < n; i++)
    {
        ll na = a ^ arr[i], nb = b ^ arr[i];
        if (na - a > nb - b)
        {
            a = na;
        }
        else if (na - a < nb - b)
        {
            b = nb;
        }
        else
        {
            return max(solve(na, b, i + 1), solve(a, nb, i + 1));
        }
    }
    return a + b;
}

void run()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", arr + i);
    }

    printf("%lld\n", solve());
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}