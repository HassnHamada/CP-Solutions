#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// const int N = 1e5 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
// int aaa[N], bbb[N], ddd[N], tak[N];

void run()
{
    int h, w, r, c;
    scanf("%d%d%d%d", &h, &w, &r, &c);
    int ans = 4;
    ans -= r == 1;
    ans -= r == h;
    ans -= c == 1;
    ans -= c == w;
    printf("%d\n", ans);
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