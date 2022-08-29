#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 64, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

bool solve(int n, int m, int k)
{
    int u = 0;
    for (int i = 0; i < k; i++)
    {
        int v = (arr[i] / n);
        if (v < 2)
        {
            continue;
        }
        if (v >= m)
        {
            return true;
        }
        if (v > 2)
        {
            u += v - 2;
        }
        m -= v;
        if (m == 1)
        {
            if (u == 0)
            {
                m += 2;
            }
            else
            {
                m += 1;
                u -= 1;
            }
        }
    }
    return false;
}

void run()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", arr + i);
    }
    bool ok = solve(n, m, k) || solve(m, n, k);
    printf(ok ? "Yes\n" : "No\n");
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