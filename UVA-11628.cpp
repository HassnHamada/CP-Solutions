#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e4 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    while (true)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        if (n == 0 && m == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", arr + i);
            }
        }
        int t = 0;
        for (int i = 0; i < n; i++)
        {
            t += arr[i];
        }
        assert(t);
        for (int i = 0; i < n; i++)
        {
            int a = arr[i], b = t;
            int g = __gcd(a, b);
            printf("%d / %d\n", a / g, b / g);
        }
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