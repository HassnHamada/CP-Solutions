#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// const int N = 3e5 + 10, M = 5e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
// ll inp[N];

void run()
{
    int n, z;
    scanf("%d%d", &n, &z);
    int ans = 0;
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        ans = max(ans, v | z);
    }
    printf("%d\n", ans);
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
