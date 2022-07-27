#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int arr[N];
ll aaa[N], bbb[N];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    aaa[1] = bbb[n] = 0;
    for (int i = 2; i <= n; i++)
    {
        aaa[i] = aaa[i - 1] + max(0, arr[i - 1] - arr[i]);
    }
    for (int i = n - 1; i; i--)
    {
        bbb[i] = bbb[i + 1] + max(0, arr[i + 1] - arr[i]);
    }
    for (int i = 0; i < m; i++)
    {
        int s, t;
        scanf("%d%d", &s, &t);
        if (s < t)
        {
            printf("%lld\n", aaa[t] - aaa[s]);
        }
        else if (s > t)
        {
            printf("%lld\n", bbb[t] - bbb[s]);
        }
        else
        {
            assert(false);
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