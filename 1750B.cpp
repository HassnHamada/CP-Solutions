#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, M = 3, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char inp[N];

void run()
{
    int n;
    scanf("%d%s", &n, inp);
    ll ans = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        if (inp[i] == '0')
        {
            j = 0;
        }
        else
        {
            j++;
            ans = max(ans, 1ll * j * j);
        }
    }
    for (int i = 0, j = 0; i < n; i++)
    {
        if (inp[i] == '1')
        {
            j = 0;
        }
        else
        {
            j++;
            ans = max(ans, 1ll * j * j);
        }
    }
    int m = count(inp, inp + n, '0');
    printf("%lld\n", max(ans, 1ll * m * (n - m)));
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