#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 10, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, _; i < m; i++)
    {
        scanf("%d%d", &_, &_);
    }
    printf(n <= m ? "NO\n" : "YES\n");
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
