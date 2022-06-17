#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
// char aaa[N], bbb[N];

void run()
{
    int n;
    scanf("%d", &n);
    int m = (n - 3) / 3;
    n -= m * 3;
    assert(n >= 3 && n <= 5);
    if (n == 3)
    {
        printf("%d %d %d\n", m + 1, m + 2, m);
    }
    if (n == 4)
    {
        printf("%d %d %d\n", m + 1, m + 3, m);
    }
    if (n == 5)
    {
        printf("%d %d %d\n", m + 2, m + 3, m);
    }
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
