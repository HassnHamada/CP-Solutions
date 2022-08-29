#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e0 + 10, M = 7, L = 3, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

void run()
{
    int t, k, p;
    scanf("%d%d%d", &t, &k, &p);
    printf("%d\n", max(t - k * p, 0) + min(t / k, p));
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