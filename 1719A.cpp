#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 1e6 + 10, L = 1e6 + 10, Q = 448, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

// int arr[N], ans[N];

void run()
{
    ll n, m;
    scanf("%lld%lld", &n, &m);
    printf((n + m - 2) & 1 ? "Burenka\n" : "Tonya\n");
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
