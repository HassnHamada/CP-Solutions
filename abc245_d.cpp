#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e2 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int aaa[N], bbb[N], ccc[N];

// a4 a3 a2 a1 a0
// c7 c6 c5 c4 c3 c2 c1 c0
// b3 b2 b1 b0

// c7 = a4*b3
// c6 = a3*b3 + a4*b2
// c5 = a2*b3 + a3*b2 + a4*b1
// c4 = a1*b3 + a2*b2 + a3*b1 + a4*b0
// c3 = a0*b3 + a1*b2 + a2*b1 + a3*b0
// c2 = a0*b2 + a1*b1 + a2*b0
// c1 = a0*b1 + a1*b0
// c0 = a0*b0

// c7 = 0
// c6 = 0
// c5 = 0
// c4 = a4*b0
// c3 = a3*b0
// c2 = a2*b0
// c1 = a1*b0
// c0 = a0*b0

// already submitted
void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", aaa + i);
    }
    for (int i = 0; i <= n + m; i++)
    {
        scanf("%d", ccc + i);
    }
    for (int i = m; i >= 0; i--)
    {
        bbb[i] = ccc[i + n] / aaa[n];
        for (int j = 0; j <= n; j++)
        {
            ccc[i + j] -= bbb[i] * aaa[j];
        }
    }
    assert(all_of(ccc, ccc + n + m + 1, [](int x)
                  { return x == 0; }));
    for (int i = 0; i <= m; i++)
    {
        printf("%d%c", bbb[i], " \n"[i == m]);
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