#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// const int N = 3e5 + 10, M = 5e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
// ll inp[N];

void run()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0, v, s = 0; i <= n; i++)
    {
        if (i == n)
        {
            if (s)
            {
                ans += 1;
            }
            break;
        }
        scanf("%d", &v);
        if (v)
        {
            s += 1;
        }
        else
        {
            if (s)
            {
                ans += 1;
            }
            s = 0;
        }
    }
    printf("%d\n", min(ans, 2));
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
