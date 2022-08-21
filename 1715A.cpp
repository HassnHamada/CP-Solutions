#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e6 + 10, M = 6, MOD = 1e9 + 9, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if (n > m)
    {
        swap(n, m);
    }
    printf("%d\n", m == 1 ? 0 : 2 * (n - 1) + (m - 1) + 1);
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